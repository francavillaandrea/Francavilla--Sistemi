#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5       // Dimensione dei vettori
#define MAX 10    // Valore massimo per i numeri casuali

int main() {
    int V1[N], V2[N], V3[N];
    
    // Inizializzazione del generatore di numeri casuali
    srand(time(NULL));
    
    // Riempimento dei vettori V1 e V2 con numeri casuali
    printf("V1: ");
    for(int i = 0; i < N; i++) {
        V1[i] = rand() % MAX;
        printf("%d ", V1[i]);
    }
    
    printf("\nV2: ");
    for(int i = 0; i < N; i++) {
        V2[i] = rand() % MAX;
        printf("%d ", V2[i]);
    }
    
    // Calcolo del prodotto vettoriale
    printf("\nProdotto vettoriale (V3): ");
    for(int i = 0; i < N; i++) {
        V3[i] = V1[i] * V2[i];
        printf("%d ", V3[i]);
    }
    printf("\n");
    
    return 0;
}