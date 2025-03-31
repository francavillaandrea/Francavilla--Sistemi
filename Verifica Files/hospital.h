#define MAX_LENGTH 100
#include <string.h>

// define struct Patient
typedef struct{
  char name [MAX_LENGTH];
  char DOB [MAX_LENGTH];
  int weight;
  int height;

} Patient;


// define struct ScheduledVisit

typedef struct{
  char patientName [MAX_LENGTH];
  char visitorName [MAX_LENGTH];
  char date [MAX_LENGTH];
  char time [MAX_LENGTH];
}ScheduledVisit;
/**
 * createMenu creates a user menù with the following options:
 * 1 - Print current patients count
 * 2 - Print patients
 * 3 - Add new patient
 * 4 - Add new visit to schedule
 * 5 - Print patient scheduled visits
 * If the line is empty, -1 is returned
 * If the choice is valid, its number is returned.
 */
int createMenu() {
    // implement function logic here
  int choice;
    printf("1 - Print current patient count\n2 - Print patient\n3 - Add new patient\n4 - Add new visit to schedule\n5 - Print patient scheduled visits\n");
    scanf("%d", &choice);
    return choice;
}

/**
 * getCurrentPatientsCount returns the number of patients available in the
 * "patients.txt" file.
 * Returns -1 in case of any error.
 */
int getCurrentPatientsCount() {

  // implement function logic here
  int count  = 0;
  FILE *fp = fopen("./patients.txt", "r");
  if(fp == NULL)
  {
      return -1;
  }
  while(!feof(fp))
  {
    Patient p;
      fscanf(fp, "%s %s %d %d ", p.name, p.DOB, &p.weight, &p.height);
      count++;
  }
  fclose(fp);
  return count;
}

/*
 * printPatients prints each scheduled patient in the
 * file "patients.txt", one by line, with the following format
 *
 * Patient Name - Birth date - Weight in kg - Height in cm
 * 
 * Example:
 ** Luca_Anselma - 1998-10-10 - 92 kg - 193 cm
 */


int printPatients(){
  Patient patient;
  FILE *fp = fopen("./patients.txt", "r");
  if(fp == NULL)
  {
      return -1;
  }
  while(!feof(fp))
  {
      fscanf(fp, "%s %s %d %d ", patient.name, patient.DOB, &patient.weight, &patient.height);
      printf("%s - %s - %d kg - %d cm\n", patient.name, patient.DOB, patient.weight, patient.height);
  }
  fclose(fp);
  return 0;
}


/**
 * addNewPatient adds a new patient to the patients file.
 * Returns -1 in case of any error.
 */

 int addNewPatients(Patient p){
  FILE *fp = fopen("./patients.txt", "a");
  if (fp == NULL)
  {
      return -1;
  }
  fprintf(fp, "%s %s %d %d\n", p.name, p.DOB, p.weight, p.height);
  fclose(fp);
  return 0;
}

/*
 * addNewScheduledVisit adds a new visit to the visits file.
 * Returns -1 in case of any error.
 */
int addNewScheduledVisit(ScheduledVisit v)
{
    FILE *fv = fopen("./visits.txt", "a");
    if (fv == NULL)
    {
      return -1;
    }
    fprintf(fv, "\n %s %s %s %s", v.patientName, v.visitorName, v.date, v.time);
    fclose(fv);
    return 0;
}

/**
 * printPatientVisitors prints the information about all visitors of a
 * specified patient.
 * Returns -1 in case of any error.
 */
 int printPatientVisits(char patientName[MAX_LENGTH])
 {
     ScheduledVisit visit;
     FILE *fp = fopen("./visits.txt", "r");
     if (fp == NULL)
     {
         return -1;
     }
     while(!feof(fp))
     {
         fscanf(fp, "%s %s %s %s\n",visit.patientName, visit.visitorName, visit.date, visit.time);
         if(strcmp(visit.patientName, patientName) == 0)
         {
             printf("%s\n",visit.visitorName);
         }
     }
     fclose(fp);
     return 0;
 }

/**
 * doOperation takes the number representing a choice and
 * executes the corresponding operation
 * Returns -1 in case of any error.
 */
int doOperation(int choice)
{
  //implement function logic here
    Patient paziente;
    ScheduledVisit visit;
    switch (choice)
    {
        case 1:
            printf("%d", getCurrentPatientsCount());
            break;
        case 2:
            printPatients();
            break;
        case 3:
            printf("Inserire il nome ed il cognome del paziente, la sua data di nascita il suo peso e la sua altezza: \n");
            scanf("%s %s %d %d", paziente.name, paziente.DOB, &paziente.weight, &paziente.height);
            addNewPatients(paziente);
            break;
        case 4:
            printf("Inserisci i dati della visita: \n");
            scanf("%s %s %s %s ", visit.patientName, visit.visitorName, visit.date, visit.time);
            addNewScheduledVisit(visit);
            break;
        case 5:
            printf("Inserisci il nome del paziente: ");
            scanf("%s", paziente.name);
            printPatientVisits(paziente.name);
            break;
        default:
            printf("Invalid choice \n");
            break;

    }
    return 0;
}

