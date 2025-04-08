#include <stdio.h>

#include "bookshop.h"

int main(void) {
  printf("Seleziona una voce dal menù, digitando un numero\n");

  int choice = createMenu();
  if (choice < 0 || choice > 5) {
    printf("ERRORE: SCELTA NON VALIDA\n");
    return -1;
  }

  return doOperation(choice);
}