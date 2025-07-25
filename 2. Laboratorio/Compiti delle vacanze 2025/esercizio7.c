#include <stdio.h>

#define N 4   // Dimensione dei vettori

int main() {
    char V1[N] = {'Q', 'R', 'Y', 'G'};  // Vettore dei caratteri
    int V2[N] = {3, 5, 0, 3};           // Vettore delle ripetizioni
    
    printf("Caratteri ripetuti: ");
    
    // Per ogni posizione nei vettori
    for(int i = 0; i < N; i++) {
        // Ripeti il carattere V1[i] per V2[i] volte
        for(int j = 0; j < V2[i]; j++) {
            printf("%c", V1[i]);
        }
    }
    printf("\n");
    
    return 0;
}