#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// include missing libraries

#define MAX_LENGTH 100

// define struct Student here
typedef struct
{
  char firstName[MAX_LENGTH];
  char lastName[MAX_LENGTH];
  char class[MAX_LENGTH];
  int avgGrades;
} Student;

/**
 * readStudents reads the file represented by the pointer and populates the
 * students array of structs. Returns the number of read students.
 */
int readStudents(Student students[MAX_LENGTH])
{
  FILE *sourceFile = fopen("./students.csv", "r");
  if (sourceFile == NULL)
  {
    return -1;
  }
  int nOfStudents = 0;
  while (feof(sourceFile))
  {
    fscanf(sourceFile, "%s %s %s %d\n", students[nOfStudents].firstName, students[nOfStudents].lastName, students[nOfStudents].class, students[nOfStudents].avgGrades);
    nOfStudents++;
  }
  return nOfStudents;
  fclose(sourceFile);
}

/**
 * studentsInClass returns the number of students in a particular class.
 */
int studentsInClass(Student students[MAX_LENGTH], int n, char studentClass[MAX_LENGTH])
{
  int cnt = 0;
  for (int i = 0; i < n ;i++){ 
    if(strcmp(students[i].class, studentClass) == 0)
    {
      cnt++;
    }
  }
  
  return cnt;
}


/**
 * printStudentNames prints the full name of each student, one by line.
 */
void printStudentNames(Student students[MAX_LENGTH], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%s %s",students[i].firstName, students[i].lastName );
  }
  
}

/**
 * serializeStudents saves the array of Students in a CSV file specified by destPath.
 * serializeStudents сохраняет массив студентов в файле CSV, указанном в параметре destPath.
 */
void serializeStudents(Student students[MAX_LENGTH], int n, char destPath[MAX_LENGTH])
{
  FILE *destFile = fopen("./students.csv", "r");
  if (destFile == NULL)
  {
    return -1;
  }
    for (int i = 0; i < n; i++)
    {
     fprintf(destFile, "%s %s %s %d", students[i].firstName,students[i].lastName,students[i].class,&students[i].avgGrades);
    }
    fclose(destFile );
}