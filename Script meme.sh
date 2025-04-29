#!/bin/bash

# ─────────────────────────────
# Funzione per messaggi colorati
function echo_color() {
    local color_code="$1"
    shift
    echo -e "\033[${color_code}m$*\033[0m"
}

# ─────────────────────────────
# Template di testo predefiniti
declare -A templates=(
  [1]="Questo è un esempio di template educativo."
  [2]="Lorem ipsum dolor sit amet, consectetur adipiscing elit."
  [3]="🌟 Meme Script attivo! Ripetizione automatica in corso..."
)

# ─────────────────────────────
# Cartelle
desktop_dir=~/Desktop
base_dir="$desktop_dir/ScriptMemeLogs"
current_date=$(date '+%Y-%m-%d')  # Cartella per giorno
session_dir="$base_dir/$current_date"

# Crea la cartella per la giornata
mkdir -p "$session_dir"

# ─────────────────────────────
# Scelta nome file
while true; do
    read -p "📄 Inserisci il nome del file (senza estensione): " nome_file
    if [[ -z "$nome_file" ]]; then
        echo_color 31 "⚠️  Il nome del file non può essere vuoto."
    else
        nome_file="${nome_file}.txt"
        break
    fi
done

# ─────────────────────────────
# Scelta template o inserimento manuale
echo "🧠 Vuoi usare un template?"
select template_opt in "Template 1" "Template 2" "Template 3" "Scrivi manualmente"; do
    case $REPLY in
        1|2|3)
            contenuto="${templates[$REPLY]}"
            break
            ;;
        4)
            read -p "✍️  Inserisci il contenuto: " contenuto
            break
            ;;
        *) echo_color 31 "⚠️  Scelta non valida." ;;
    esac
done

# ─────────────────────────────
# Numero di ripetizioni
while true; do
    read -p "🔁 Quante volte vuoi scrivere il contenuto? " ripetizioni
    if [[ "$ripetizioni" =~ ^[1-9][0-9]*$ ]]; then
        break
    else
        echo_color 31 "⚠️  Inserisci un numero intero positivo."
    fi
done

# ─────────────────────────────
# Scrittura file (sovrascrittura)
output_file="$session_dir/$nome_file"

# Se il file esiste già, verrà sovrascritto
echo "$contenuto" > "$output_file"
for ((i = 1; i < ripetizioni; i++)); do
    echo "$contenuto" >> "$output_file"
done

# Backup per annullare operazione
cp "$output_file" "$base_dir/last_operation_backup.txt"

# ─────────────────────────────
# Log
log_file="$base_dir/log_script.txt"
utente=$(whoami)
hash_contenuto=$(echo -n "$contenuto" | sha256sum | awk '{print $1}')
numero=$(grep -c "Operazione n°" "$log_file" 2>/dev/null || echo 0)
numero=$((numero + 1))

log_temp=$(mktemp)
{
    echo "----------------------------"
    echo "Operazione n° $numero"
    echo "Utente: $utente"
    echo "Data: $(date '+%Y-%m-%d %H:%M:%S')"
    echo "File: $nome_file"
    echo "Ripetizioni: $ripetizioni"
    echo "Contenuto (hash): $hash_contenuto"
    echo "Anteprima: ${contenuto:0:50}..."
    echo "Percorso: $output_file"
    echo ""
} > "$log_temp"

# Inserisce il nuovo log in cima al file esistente
if [[ -f "$log_file" ]]; then
    cat "$log_temp" "$log_file" > "${log_file}.tmp" && mv "${log_file}.tmp" "$log_file"
else
    mv "$log_temp" "$log_file"
fi

# ─────────────────────────────
# Risultato
echo_color 32 "✅ File creato/sovrascritto: $output_file"
echo_color 36 "📚 Log aggiornato: $log_file"

# Apertura automatica
case "$OSTYPE" in
  linux*)   xdg-open "$output_file" ;;
  darwin*)  open "$output_file" ;;
  cygwin* | msys*) start "$output_file" ;;
  *)        echo_color 33 "⚠️  Impossibile aprire automaticamente il file." ;;
esac

# ─────────────────────────────
# Ripristino file precedente (funzione undo)
read -p "↩️  Vuoi annullare l'ultima operazione? (s/N): " undo
if [[ "$undo" == "s" || "$undo" == "S" ]]; then
    if [[ -f "$base_dir/last_operation_backup.txt" ]]; then
        cp "$base_dir/last_operation_backup.txt" "$output_file"
        echo_color 33 "🔁 Ultima operazione annullata: file ripristinato."
    else
        echo_color 31 "❌ Nessun backup disponibile."
    fi
fi

read -p "Premi INVIO per uscire..."
