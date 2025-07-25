#include <stdio.h>

int main() {
    float num1, num2, risultato;
    char operazione;
    
    // Input dei numeri e dell'operazione
    printf("Inserisci il primo numero: ");
    scanf("%f", &num1);
    
    printf("Inserisci il secondo numero: ");
    scanf("%f", &num2);
    
    printf("Inserisci l'operazione (+, -, *, /): ");
    scanf(" %c", &operazione);
    
    // Esecuzione dell'operazione richiesta
    switch(operazione) {
        case '+':
            risultato = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, risultato);
            break;
        case '-':
            risultato = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, risultato);
            break;
        case '*':
            risultato = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, risultato);
            break;
        case '/':
            if(num2 != 0) {
                risultato = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, risultato);
            } else {
                printf("Errore: divisione per zero!\n");
            }
            break;
        default:
            printf("Errore: operazione non valida!\n");
            break;
    }
    
    return 0;
}