#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "files.h"

#define MAX_LENGTH 100

int main(void) {
  Student students[MAX_LENGTH];
  
  int n = readStudents(students);
  if (n > 0) {
    printf("File letto correttamente\n");

    printf("Trovati %d studenti\n", n);
  }

  int studentsIn3B = studentsInClass(students, n, "3B");
  printf("La classe 3B ha %d studenti\n", studentsIn3B);

  int studentsIn5B = studentsInClass(students, n, "5B");
  printf("La classe 3B ha %d studenti\n", studentsIn5B);

  printStudentNames(students, n);

  serializeStudents(students, n, "dest-students.csv");

  return 0;
}
