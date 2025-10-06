#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50    // Valore massimo dei numeri casuali
#define N 10      // Dimensione del vettore

int main() {
    int V[N];
    int somma = 0;
    float media;
    
    // Inizializza il generatore di numeri casuali
    srand(time(NULL));
    
    // Riempimento del vettore con numeri casuali
    printf("Vettore generato: ");
    for(int i = 0; i < N; i++) {
        V[i] = 1 + rand() % MAX;  // Genera numeri da 1 a 50
        printf("%d ", V[i]);
        somma += V[i];
    }
    
    // Calcolo della media
    media = (float)somma / N;
    
    printf("\nLa somma degli elementi è: %d\n", somma);
    printf("La media degli elementi è: %.2f\n", media);
    
    return 0;
}