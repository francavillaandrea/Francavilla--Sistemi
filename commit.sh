#!/bin/bash

# Verifica che lo script sia eseguito in Git Bash
if [[ ! $(which git) ]]; then
    echo "Questo script richiede Git Bash per funzionare."
    exit 1
fi

# Salva la directory iniziale
INITIAL_DIR="$(pwd)"

# Colori per il output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Funzione per ripristinare la directory iniziale
restore_directory() {
    cd "$INITIAL_DIR" || exit 1
}

# Trap per assicurarsi di tornare alla directory iniziale in caso di interruzione
trap restore_directory EXIT

# Funzione per convertire percorsi Windows in percorsi Git Bash
convert_path() {
    echo "$1" | sed 's/\\/\//g' | sed 's/C:/\/c/g'
}

# Funzione per stampare il separatore
print_separator() {
    echo -e "${BLUE}----------------------------------------${NC}"
}

# Funzione per verificare se una directory è una repository git
is_git_repo() {
    if [ -d "$1/.git" ]; then
        return 0
    else
        return 1
    fi
}

# Funzione per gestire gli errori
handle_error() {
    echo -e "${RED}Errore: $1${NC}"
    exit 1
}

# Funzione per il push di una singola repository
push_repository() {
    local repo_path="$1"
    local repo_name=$(basename "$repo_path")
    
    cd "$repo_path" 2>/dev/null || { handle_error "Impossibile accedere a $repo_path"; return 1; }
    
    if ! is_git_repo .; then
        echo -e "${RED}$repo_path non è una repository git valida${NC}"
        restore_directory
        return 1
    fi
    
    echo -e "${YELLOW}Pushing $repo_name...${NC}"
    
    # Verifica se ci sono modifiche da committare
    if [[ $(git status --porcelain) ]]; then
        git add . || handle_error "Git add fallito per $repo_name"
        git commit -m "Update $repo_name" || handle_error "Git commit fallito per $repo_name"
        git push || handle_error "Git push fallito per $repo_name"
        echo -e "${GREEN}Push della repository '$repo_name' effettuato con successo${NC}"
    else
        echo -e "${YELLOW}Nessuna modifica da committare in $repo_name${NC}"
    fi
    
    print_separator
}

# Funzione per il pull di una singola repository
pull_repository() {
    local repo_path="$1"
    local repo_name=$(basename "$repo_path")
    
    cd "$repo_path" || handle_error "Impossibile accedere a $repo_path"
    
    if ! is_git_repo .; then
        echo -e "${RED}$repo_path non è una repository git valida${NC}"
        return 1
    fi
    
    echo -e "${YELLOW}Pulling $repo_name...${NC}"
    
    # Verifica se ci sono modifiche locali prima del pull
    if [[ $(git status --porcelain) ]]; then
        echo -e "${YELLOW}Attenzione: Ci sono modifiche locali non committate in $repo_name${NC}"
        read -p "Vuoi fare stash delle modifiche prima del pull? (s/n): " choice
        if [[ $choice == "s" ]]; then
            git stash || handle_error "Git stash fallito per $repo_name"
        fi
    fi
    
    git pull || handle_error "Git pull fallito per $repo_name"
    
    # Se abbiamo fatto lo stash, proviamo a riapplicarlo
    if [[ $choice == "s" ]]; then
        git stash pop || handle_error "Git stash pop fallito per $repo_name"
    fi
    
    echo -e "${GREEN}Pull della repository '$repo_name' effettuato con successo${NC}"
    print_separator
}

# Array delle repository con percorsi convertiti
REPOS=(
    "$(convert_path 'C:\Users\paolc\Desktop\Repos\Drive')"
    "$(convert_path 'C:\Users\paolc\Desktop\Repos\Francavilla--Informatica')"
    "$(convert_path 'C:\Users\paolc\Desktop\Repos\Francavilla--Sistemi')"
    "$(convert_path 'C:\Users\paolc\Desktop\Repos\Francavilla--Telecomunicazioni')"
    "$(convert_path 'C:\Users\paolc\Desktop\Repos\Francavilla--TPSIT')"
    "$(convert_path 'C:\Users\paolc\Desktop\Repos\tpsi-playground-francavillaandrea-1')"
    "$(convert_path 'C:\Users\paolc\Desktop\Repos\crew224-hub')"
)

# Funzione per salvare l'array REPOS in un file di configurazione
save_repos() {
    local config_file="/c/Users/paolc/Desktop/git_repos.conf"
    printf "%s\n" "${REPOS[@]}" > "$config_file"
}

# Funzione per caricare l'array REPOS dal file di configurazione
load_repos() {
    local config_file="/c/Users/paolc/Desktop/git_repos.conf"
    if [ -f "$config_file" ]; then
        mapfile -t REPOS < "$config_file"
    fi
}

# Funzione per verificare che tutte le repository esistano
verify_repos() {
    local all_valid=true
    for repo in "${REPOS[@]}"; do
        if [ ! -d "$repo" ]; then
            echo -e "${RED}Repository non trovata: $repo${NC}"
            all_valid=false
        elif ! is_git_repo "$repo"; then
            echo -e "${RED}Directory non valida come repository git: $repo${NC}"
            all_valid=false
        fi
    done
    
    if [[ $all_valid == false ]]; then
        echo -e "${RED}Alcune repository non sono accessibili. Controlla i percorsi e riprova.${NC}"
        exit 1
    fi
}

# Funzione per aggiungere una nuova repository
add_repository() {
    echo -e "${YELLOW}Aggiungi una nuova repository${NC}"
    echo "1. Seleziona una cartella esistente"
    echo "2. Clona una repository da URL"
    read -p "Seleziona un'opzione: " choice

    case $choice in
        1)
            read -p "Inserisci il percorso completo della repository (es. C:\Users\username\repo): " repo_path
            repo_path=$(convert_path "$repo_path")
            
            if [ ! -d "$repo_path" ]; then
                echo -e "${RED}La directory non esiste${NC}"
                return 1
            fi
            
            if ! is_git_repo "$repo_path"; then
                echo -e "${RED}La directory non è una repository git${NC}"
                return 1
            fi
            ;;
        2)
            read -p "Inserisci l'URL della repository da clonare: " repo_url
            read -p "Inserisci il nome della cartella di destinazione: " repo_name
            repo_path=$(convert_path "C:\Users\paolc\Desktop\Repos\$repo_name")
            
            if [ -d "$repo_path" ]; then
                echo -e "${RED}La directory di destinazione esiste già${NC}"
                return 1
            fi
            
            echo -e "${YELLOW}Clonazione della repository in corso...${NC}"
            git clone "$repo_url" "$repo_path" || {
                echo -e "${RED}Errore durante la clonazione della repository${NC}"
                return 1
            }
            ;;
        *)
            echo -e "${RED}Opzione non valida${NC}"
            return 1
            ;;
    esac
    
    # Aggiungi la nuova repository all'array
    REPOS+=("$repo_path")
    
    # Salva la configurazione aggiornata
    save_repos
    
    echo -e "${GREEN}Repository aggiunta con successo${NC}"
    print_separator
}

# Carica le repository dal file di configurazione
load_repos

# Verifica iniziale delle repository
verify_repos

# Funzione per mostrare il menu delle repository
show_repos_menu() {
    echo -e "${YELLOW}Repository disponibili:${NC}"
    for i in "${!REPOS[@]}"; do
        echo "$((i+1)). $(basename "${REPOS[$i]}")"
    done
    echo "0. Torna al menu principale"
}

# Menu principale
while true; do
    echo -e "\n${GREEN}=== Git Repository Manager ===${NC}"
    echo "1. Push di tutte le repository"
    echo "2. Pull di tutte le repository"
    echo "3. Gestisci singola repository"
    echo "4. Verifica stato repository"
    echo "5. Aggiungi una repository"
    echo "0. Esci"
    print_separator
    
    read -p "Seleziona un'opzione: " choice
    
    case $choice in
        1)
            echo -e "${YELLOW}Eseguo il push di tutte le repositories...${NC}"
            print_separator
            for repo in "${REPOS[@]}"; do
                push_repository "$repo"
            done
            ;;
        2)
            echo -e "${YELLOW}Eseguo il pull di tutte le repositories...${NC}"
            print_separator
    
            for repo in "${REPOS[@]}"; do
                pull_repository "$repo"
            done
            ;;
        3)
            while true; do
                show_repos_menu
                read -p "Seleziona una repository: " repo_choice
                if [ "$repo_choice" -eq 0 ]; then
                    break
                elif [ "$repo_choice" -ge 1 ] && [ "$repo_choice" -le ${#REPOS[@]} ]; then
                    selected_repo="${REPOS[$((repo_choice-1))]}"
                    echo -e "\n${YELLOW}Operazioni disponibili per $(basename "$selected_repo"):${NC}"
                    echo "1. Push"
                    echo "2. Pull"
                    echo "3. Stato"
                    echo "0. Torna indietro"
                    
                    read -p "Seleziona un'operazione: " op_choice
                    case $op_choice in
                        1) push_repository "$selected_repo" ;;
                        2) pull_repository "$selected_repo" ;;
                        3)
                            cd "$selected_repo" || handle_error "Impossibile accedere a $selected_repo"
                            echo -e "${YELLOW}Stato di $(basename "$selected_repo"):${NC}"
                            git status
                            print_separator
                            ;;
                        0) continue ;;
                        *) echo -e "${RED}Opzione non valida${NC}" ;;
                    esac
                else
                    echo -e "${RED}Repository non valida${NC}"
                fi
            done
            ;;
        4)
            echo -e "${YELLOW}Verifico lo stato di tutte le repository...${NC}"
            print_separator
            for repo in "${REPOS[@]}"; do
                if cd "$repo" 2>/dev/null; then
                    echo -e "${GREEN}$(basename "$repo"):${NC}"
                    git status -s
                    print_separator
                else
                    echo -e "${RED}Impossibile accedere a $(basename "$repo")${NC}"
                    print_separator
                fi
            done
            ;;
        5)
            add_repository
            ;;
        0)
            echo -e "${GREEN}Arrivederci!${NC}"
            exit 0
            ;;
        *)
            echo -e "${RED}Opzione non valida${NC}"
            ;;
    esac
done
