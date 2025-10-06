#include <stdio.h>

int main() {
    int n;
    long long fattoriale = 1; // Uso long long per gestire numeri grandi
    
    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Errore: inserire un numero positivo!\n");
        return 1;
    }
    
    // Calcolo del fattoriale
    for (int i = 1; i <= n; i++) {
        fattoriale *= i;
    }
    
    printf("Il fattoriale di %d è: %lld\n", n, fattoriale);
    
    return 0;
}