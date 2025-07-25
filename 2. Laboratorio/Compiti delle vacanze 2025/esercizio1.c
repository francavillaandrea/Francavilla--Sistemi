#include <stdio.h>

int main() {
    int giorno, mese, anno, ore, minuti, secondi;
    int elementi;
    
    printf("Inserisci data e ora nel formato GG/MM/AAAA HH:MM:SS: ");
    
    // scanf restituisce il numero di elementi letti con successo
    elementi = scanf("%d/%d/%d %d:%d:%d", 
                    &giorno, &mese, &anno,
                    &ore, &minuti, &secondi);
    
    // Stampa nel nuovo formato richiesto
    printf("\nFormato convertito: %d %d %d %d %d %d\n", 
           anno, mese, giorno,
           ore, minuti, secondi);
    
    printf("Numero di elementi riconosciuti: %d\n", elementi);
    
    return 0;
}