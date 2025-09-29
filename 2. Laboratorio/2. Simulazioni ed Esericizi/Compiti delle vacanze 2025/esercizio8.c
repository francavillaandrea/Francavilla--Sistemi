#include <stdio.h>

#define N 5   // Dimensione dei vettori

int main() {
    char V1[N] = {'Q', 'R', 'Y', 'G', 'D'};  // Primo vettore
    char V2[N] = {'Q', 'H', 'S', 'G', 'D'};  // Secondo vettore
    char V3[N];                               // Vettore risultante
    int k = 0;                                // Indice per V3
    
    printf("V1: ");
    for(int i = 0; i < N; i++) {
        printf("%c ", V1[i]);
    }
    
    printf("\nV2: ");
    for(int i = 0; i < N; i++) {
        printf("%c ", V2[i]);
    }
    
    // Confronto gli elementi in posizione uguale
    for(int i = 0; i < N; i++) {
        if(V1[i] == V2[i]) {
            V3[k] = V1[i];
            k++;
        }
    }
    
    // Stampa del risultato
    printf("\nV3 (elementi uguali): ");
    for(int i = 0; i < k; i++) {
        printf("%c ", V3[i]);
    }
    printf("\n");
    
    return 0;
}