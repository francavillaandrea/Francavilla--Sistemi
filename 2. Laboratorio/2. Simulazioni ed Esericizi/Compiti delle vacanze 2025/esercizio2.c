#include <stdio.h>

int main() {
    char risultato;
    
    printf("Inserisci il risultato (1, 2, X, x): ");
    scanf(" %c", &risultato);  // Nota lo spazio prima di %c per ignorare whitespace
    
    switch(risultato) {
        case '1':
            printf("Vittoria della squadra di casa - 3 punti\n");
            break;
        case '2':
            printf("Sconfitta della squadra di casa - 0 punti\n");
            break;
        case 'X':
        case 'x':
            printf("Pareggio - 1 punto\n");
            break;
        default:
            printf("Errore: carattere non valido!\n");
            break;
    }
    
    return 0;
}