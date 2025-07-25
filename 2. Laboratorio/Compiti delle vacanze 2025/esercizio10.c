#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Funzione per verificare se un carattere è una vocale
int isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    char S[MAX];
    int i, j = 0;
    
    printf("Inserisci una stringa: ");
    gets(S);  // o fgets(S, MAX, stdin) per una versione più sicura
    
    // Rimuove le consonanti mantenendo solo vocali e altri caratteri
    for(i = 0; S[i] != '\0'; i++) {
        if(isVowel(S[i]) || !isalpha(S[i])) {
            S[j] = S[i];
            j++;
        }
    }
    S[j] = '\0';  // Termina la stringa
    
    printf("Stringa senza consonanti: %s\n", S);
    
    return 0;
}