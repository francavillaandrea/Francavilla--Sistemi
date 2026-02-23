[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=18062268)
# Esercitazione 5 - Il Linguaggio C


In questa esercitazione andremo a esplorare come possiamo usare il C per manipolare i files e le
stringhe tramite le varianti delle funzioni `printf` e `scanf` specifiche.

## Consegna

Implementare le funzioni contenute nel file `files.h`

Dovete capire da soli come inizializzare la struct `Student` nella maniera più appropriata, in 
base al file CSV che avete.

**ATTENZIONE**: alcune funzioni non hanno i test automatici!

## Gestione dei file

Potete trovare altre dispense qui: https://www.codingcreativo.it/leggere-da-un-file-in-c

Possiamo creare, manipolare e gestire i file tramite la libreria C standard.

Per fare ciò iniziamo distinguendo i tipi di files possibili:

- Binari
- Testuali

### Apertura e chiusura di file

I file prima di essere manipolati devono essere aperti, e quando la loro manipolazione è terminata
occorre chiuderli per garantire che le ultime modifiche vengano scritte su disco.

Per aprire un file si usa la funzione `fopen` e per chiuderlo `fclose`

Per scoprire se siamo alla fine del file usiamo la funzione `feof`

Ecco un pratico esempio:


``` C
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("./mio-file.txt", "r");

  if (fp == NULL) {
    printf("Errore di apertura del file\n");
  }

  // ...

  bool endOfFile = feof(fp);
  if (endOfFile) {
    printf("Fine del file\n");
  }

  fclose(fp);
}
```

Un file può essere aperto in più modi:


| valore | Modalità | Tipo file   | Se il file non esiste |
| ------ | -------  | ----------- | --------------------- |
| `r`    | Lettura  | testuali    | errore |
| `rb`   | Lettura  | binari      | errore |
| `r+`   | Lettura e Scrittura | testuali    | errore |
| `rb+`  | Lettura e Scrittura | binari      | errore |
| `w`    | Scrittura | testuali    | viene creato |
| `wb`   | Scrittura | testuali    | viene creato |
| `w+`   | Scrittura e Lettura | testuali    | viene creato |
| `wb+`  | Scrittura | testuali  | viene creato |
| `a`    | Appendi | testuali    | viene creato |
| `ab`   | Appendi | binari      | viene creato |
| `a+`   | Appendi | testuali    | viene creato |
| `ab+`  | Appendi | binari      | viene creato |

### I files testuali


I files testuali invece sono dei file con una codifica testuale (di base ASCII oppure UTF-8)
e rappresentano file che possono essere letti o manipolati da editor di testo (file di codice,
files di configurazione, ecc...).


Per leggere da un file usiamo la funzione `fgets` (se vogliamo leggere una riga per intero in una stringa)
oppure con la funzione `fscanf` (che funziona in modo analogo alla `scanf` tradizionale)


``` C
#include <stdio.h>
#include <stdlib.h>

int main() {
  
  FILE *destFile = fopen("./altro-file", "w");

  if (sourceFile == NULL || destFile == NULL) {
    printf("Errore di apertura di un file\n");
  }

  int valore;
  fscanf(sourceFile, "%d", &valore);

  fprintf(destFile, "%d\n", valore);

  fclose(sourceFile);
  fclose(destFile);
}
```

### I files binari


I files binari sono dei file su cui i file vengono scritti byte per byte, senza una codifica
particolare, vengono usati per lo più per scrivere dei file che non saranno letti da editor 
di testo (es. file archivio, eseguibili, ecc...).


Per operare su files binari dobbiamo aprirli nella modalità adatta (`rb`, `wb`, `ab`, `rb+`, `wb+`, `ab+`)


Per leggere da files binari si usa la funzione `fread` mentre per scrivere la funzione `fwrite`.


Entrambe come parametro richiedono:
1. puntatore alla struttura dati da scrivere sul file
2. dimensione della struttura dati (possiamo ottenerla usando la parola chiave `sizeof`)
3. quantità di dati dello stesso tipo da salvare
4. puntatore al `FILE` su cui operare


Esempio di `fread`:

``` C
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
   int n1;
   int n2;
   int n3;
} threeNum;

int main()
{
   int n;
   threeNum num;
   FILE *fptr = fopen("./mio-file","rb");

   if (fptr == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   for(n = 1; n < 5; ++n)
   {
      fread(&num, sizeof(threeNum), 1, fptr); 
      printf("n1: %d\tn2: %d\tn3: %d\n", num.n1, num.n2, num.n3);
   }
   fclose(fptr); 
  
   return 0;
}
```

Esempio di `fwrite`:

``` C
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
   int n1;
   int n2;
   int n3;
} threeNum;

int main()
{
   int n;
   threeNum num;
   FILE *fptr = fopen("./mio-file","wb");

   if (fptr == NULL) {
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   for(n = 1; n < 5; ++n)
   {
      num.n1 = n;
      num.n2 = 5*n;
      num.n3 = 5*n + 1;
      fwrite(&num, sizeof(threeNum), 1, fptr); 
   }
   fclose(fptr); 
  
   return 0;
}
```

## Rinominare / Spostare files

Ci sono varie funzioni che si possono usare con i file, ma la più degna di nota è la funzione
`rename(nome_vecchio, nome_nuovo)` che permette di spostare (o rinominare) un file.

``` C 
#include <stdio.h>

int main() {
  rename("./file-prova.txt", "./file-prova-rinominato.txt");
}
```

> Esercitazione a opera di [***Alessandro Sanino***](https://linkedin.com/in/alessandrosanino)
