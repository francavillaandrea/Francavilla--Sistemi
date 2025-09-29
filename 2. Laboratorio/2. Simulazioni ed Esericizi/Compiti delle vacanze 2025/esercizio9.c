#include <stdio.h>
#include <string.h>

#define MAX 100

// Funzione per verificare se un carattere è una vocale
int isVowel(char c) {
    c = tolower(c);  // Converte in minuscolo per il confronto
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    char S[MAX];
    char temp[MAX];
    int i, j = 0;
    
    printf("Inserisci una stringa: ");
    gets(S);  // o fgets(S, MAX, stdin) per una versione più sicura
    
    // Copia la stringa raddoppiando le vocali
    for(i = 0; S[i] != '\0'; i++) {
        temp[j] = S[i];
        j++;
        if(isVowel(S[i])) {
            temp[j] = S[i];  // Raddoppia la vocale
            j++;
        }
    }
    temp[j] = '\0';  // Termina la stringa
    
    // Copia il risultato in S
    strcpy(S, temp);
    
    printf("Stringa con vocali raddoppiate: %s\n", S);
    
    return 0;
}