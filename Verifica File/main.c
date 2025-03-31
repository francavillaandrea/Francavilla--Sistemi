#define MAX_LENGTH 100

// define struct Patient
typedef struct
{
   char nome[MAX_LENGTH];
   char data[MAX_LENGTH];
   int peso;
   int altezza;
} Patient;

// define struct ScheduledVisit
typedef struct {
   char nomePaziente[MAX_LENGTH];
   char nomeDottore[MAX_LENGTH];
   char data[MAX_LENGTH];
   char ora[MAX_LENGTH];
} ScheduledVisit;

int createMenu() {
  int choice;
  printf("1 - Print current patients count\n2 - Print patients\n3 - Add new patient\n4 - Add new visit to schedule\n5 - Print patient scheduled visits\n");
  scanf("%d", &choice);
  return choice;
}

int doOperation(int choice) {
  Patient paziente;
  ScheduledVisit visit;
  int count;

  switch (choice) {
    case 1:
      count = getCurrentPatientsCount();
      printf("Il numero di pazienti nel file è: %d\n", count);
      break;
    case 2:
      printPatients();
      break;
    case 3:
      printf("Inserire i dati del paziente da aggiungere: ");
      scanf("%s %s %d %d", paziente.nome, paziente.data, &paziente.peso, &paziente.altezza);
      addNewPatient(paziente);
      break;
    case 4:
      printf("Aggiungere i dati della visita: \n");
      scanf("%s %s %s %s", visit.nomePaziente, visit.nomeDottore, visit.data, visit.ora);
      addNewScheduledVisit(visit);
      break;
    case 5:
      printf("Inserisci il nome del paziente: ");
      scanf("%s", paziente.nome);
      printPatientVisits(paziente.nome);
      break;
    default:
      printf("Invalid choice.\n");
  }
  return 0;
}

int getCurrentPatientsCount() {
  int count = 0;
  FILE *fp = fopen("./patients.txt", "r");
  if (fp == NULL) {
    return -1;
  }

  while (!feof(fp)) {
    Patient p;
    fscanf(fp, "%s %s %d %d", p.nome, p.data, &p.peso, &p.altezza);
    count++;
  }
  fclose(fp);
  return count;
}

int printPatients() {
  Patient patient;
  FILE *fp = fopen("./patients.txt", "r");
  if (fp == NULL) {
    return -1;
  }

  while (fscanf(fp, "%s %s %d %d", patient.nome, patient.data, &patient.peso, &patient.altezza) != EOF) {
    printf("%s - %s - %d Kg - %d Cm\n", patient.nome, patient.data, patient.peso, patient.altezza);
  }
  fclose(fp);
  return 0;
}

int addNewPatient(Patient patient) {
  FILE *fp = fopen("./patients.txt", "a");
  if (fp == NULL) {
    return -1;
  }

  fprintf(fp, "%s %s %d %d\n", patient.nome, patient.data, patient.peso, patient.altezza);
  fclose(fp);
  return 0;
}

int addNewScheduledVisit(ScheduledVisit visit) {
  FILE *fp = fopen("./visits.txt", "a");
  if (fp == NULL) {
    return -1;
  }

  fprintf(fp, "%s %s %s %s\n", visit.nomePaziente, visit.nomeDottore, visit.data, visit.ora);
  fclose(fp);
  return 0;
}

int printPatientVisits(char patientName[MAX_LENGTH]) {
  ScheduledVisit visit;
  FILE *fp = fopen("./visits.txt", "r");
  if (fp == NULL) {
    return -1;
  }

  while (fscanf(fp, "%s %s %s %s", visit.nomePaziente, visit.nomeDottore, visit.data, visit.ora) != EOF) {
    if (strcmp(visit.nomePaziente, patientName) == 0) {
      printf("%s - %s - %s - %s\n", visit.nomePaziente, visit.nomeDottore, visit.data, visit.ora);
    }
  }
  fclose(fp);
  return 0;
}