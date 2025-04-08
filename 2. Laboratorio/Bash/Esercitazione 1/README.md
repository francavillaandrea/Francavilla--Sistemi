[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=16718704)
# Sistemi e Reti - Classi Terze - Bash - Lezione 1

In questa esercitazione impareremo a usare i comandi bash visti finora

## Il comando `man`

Il comando `man` viene usato per ottenere informazioni (in inglese) dal manuale che esiste per un determinato altro comando.

Viene utilizzato come segue:

``` bash
man [altro-comando]
```

## Il comando `echo`

Il comando `echo` viene usato per mostrare a video una determinata stringa

Viene usato come segue:

``` bash
echo "guarda che roba!"
```

## Il comando `pwd`

Il comando `pwd` ("print-working-directory" -> stampa la directory di lavoro, in inglese) viene usato per mostrare a video la cartella di lavoro

Viene usato come segue:

``` bash
pwd
```

## Il comando `cd`

Il comando `cd` ("change-directory" -> cambia directory, in inglese) viene usato per cambiare la cartella di lavoro (ovvero spostarci all'interno del pc)

Viene usato come segue:

``` bash
cd <directory>
# per esempio
cd ./Desktop
```

## Il comando `ls`

Il comando `ls` viene usato per ottenere la lista dei file in una determinata directory, se non si specifica nessuna directory, viene presa in considerazione la directory corrente.

Viene utilizzato come segue:

``` bash
ls 
ls /home/saniales/mia-cartella
ls ./mia-cartella
```

Si possono usare il flag `-l` ("long-format" -> formato lungo, in inglese) per includere più informazioni oppure `-a` ("all" -> tutto, in inglese) per includere anche i file nascosti (i file nascosti sono quelli il cui nome inizia con ".")

``` bash
ls -l -a
# oppure
ls -la
```

## Il comando `cp`

Il comando `cp` viene usato per copiare un file da una posizione sorgente a una posizione destinazione.

Viene utilizzato come segue:

``` bash
cp <sorgente> <destinazione>
# per esempio
cp file.txt /home/saniales/file.txt
```

Si possono usare il flag `-r` ("recursive" -> ricorsivo, in inglese) per copiare anche le cartelle con il loro contenuto e `-f` ("forced" -> forzato, in inglese) per copiare forzatamente (in questo modo non viene chiesta nessuna conferma)

``` bash
cp -r -f <sorgente> <destinazione>
# per esempio
cp -r -f directory /home/saniales/directory
```

## Il comando `mv`

Il comando `mv` viene usato per spostare o rinominare un file da una posizione sorgente a una posizione destinazione.

Viene utilizzato come segue:

``` bash
mv <sorgente> <destinazione>
# per esempio
mv file.txt /home/saniales/file.txt
```

## Il comando `mkdir`

Il comando `mkdir` viene usato per creare directory in una determinata posizione nel nostro pc.

Viene utilizzato come segue:

``` bash
mkdir <destinazione>
# per esempio
mkdir /home/saniales/directory
```

Si può usare il flag `-p` ("parents" -> genitori, in inglese) per creare tutte le cartelle in un determinato percorso, qualora non siano esistenti

``` bash
mkdir -p <destinazione>
# per esempio
mkdir /home/saniales/directory/directory-2
```

## Il comando `rmdir`

Il comando `rmdir` viene usato per rimuovere directory **vuote** in una determinata posizione nel nostro pc.

Se la cartella non è vuota, il comando fallisce

Viene utilizzato come segue:

``` bash
rmdir <destinazione>
# per esempio
rmdir /home/saniales/directory
```

## Il comando `rm`

Il comando `rm` viene usato per rimuovere un file da una posizione.

Viene utilizzato come segue:

``` bash
rm <file>
# per esempio
rm file.txt 
```

Si possono usare il flag `-r` ("recursive" -> ricorsivo, in inglese) per rimuovere anche le cartelle con il loro contenuto e `-f` ("forced" -> forzato, in inglese) per rimuovere forzatamente (in questo modo non viene chiesta nessuna conferma)

``` bash
rm -r -f <directory>
# per esempio
rm -r -f directory
```

## il comando `sudo`

Il comando `sudo` ("super-user-do" -> esegui come super-user, in inglese) permette di eseguire operazioni mascherandosi da utente `root`, l'amministratore di sistema. Questo utente ha poteri su ogni parte del sistema e permette di fare anche operazioni "pericolose" (come aggiornamenti o cancellare cartelle di sistema!)

Viene utilizzato come segue:

``` bash
sudo <comando>
# per esempio
sudo rm -rf / # cancella tutto il pc, comando letale
```
