# Sistemi e Reti - Classi Terze - Bash 

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

## I permessi di file e cartelle in un ambiente UNIX

Sul sistema operativo Linux, e in generale su UNIX, ogni file è associato a 
dei permessi di lettura (**r**), scrittura (**w**) ed esecuzione (**x**).

Se provate a eseguire i seguenti comandi:
``` bash
# crea una cartella
mkdir cartella-prova

# crea un file txt
touch file-prova.txt

# mostra i contenuti della cartella di lavoro
# in formato "lungo"
ls -l
```

Dovreste avere un output simile a questo
```
drwxr-xr-x 1 runner runner  0 Oct 17 08:04 cartella-prova
-rw-r--r-- 1 runner runner  0 Oct 17 08:04 file-prova.txt
-rw-r--r-- 1 runner runner 16 Nov 11  2021 main.sh
-rw-r--r-- 1 runner runner 62 Nov 11  2021 replit.nix
```

Soffermiamoci sulla prima parte di ogni riga:
```
drwxr-xr-x
```

Potete notare che ci sono 3 triplette di valori `rwx`, più un `d` all'inizio.
`d` significa semplicemente che quel file è contrassegnato come `directory` 
(ricordatevi che in UNIX "tutto è un file"). 

La prima tripletta si riferisce all'utente (`user`)

La seconda tripletta si riferisce al gruppo UNIX a cui l'utente appartiene (`group`)

La terza tripletta si riferisce a tutti gli altri (`others`)

La stessa informazione può essere rappresentata in forma numerica, sostituendo
per ogni posizione il carattere (rwx) con 1 e il carattere (-) con 0.

Ad esempio, tralasciando la prima posizione, la stringa dei permessi è la seguente:
```
rwx r-x r-x
```
e può essere riscritta in formato binario
```
rwx r-x r-x
111 101 101
```
che corrisponde al seguente formato decimale
```
7 5 5
```

Per ogni numero da 0 a 7 abbiamo una serie di permessi collegati

| decimale | binario | permessi | significato |
| -------- | ------- | -------- | ----------- |
| 0 | `000` | `---` | Nessun permesso |
| 1 | `001` | `--x` | Esecuzione |
| 2 | `010` | `-w-` | Scrittura |
| 3 | `011` | `-wx` | Scrittura ed Esecuzione |
| 4 | `100` | `r--` | Lettura |
| 5 | `101` | `r-x` | Lettura e Esecuzione |
| 6 | `110` | `rw-` | Lettura e Scrittura |
| 7 | `111` | `rwx` | Tutti i permessi (Lettura, Scrittura ed Esecuzione) |


### Il comando `chmod`

Questo comando permette di specificare i permessi di un file o una directory

Ha due modalità di uso:

#### Modalità decimale

``` bash
chmod  <permessi-in-decimale> <file>
# per esempio - например
chmod 400 file-prova.txt
```

#### Modalità testuale `ugoa+rwx`

In questa modalità si definisce i permessi in maniera testuale

- `u` -> `user`
- `g` -> `group`
- `o` -> `others`
- `a` -> `all` -> `u` + `g` + `o`

Mentre `r`, `w` e `x` già li conosciamo

``` bash
chmod <permessi> <file>

# per esempio
chmod a+r file-prova.txt
# oppure
chmod u+w file-prova.txt u+w
# oppure
chmod g+rwx file-prova.txt g+rwx
```

### Il comando `cat`

![ukrainian levkoy cat](./.lesson/assets/ukrainian-levkoy-cat.webp)

Questo comando permette di leggere il contenuto di un file

``` bash
cat <file>
# per esempio
cat file-prova.txt
```
 
### Il comando `chown`

Questo comando permette di cambiare il proprietario di un file

``` bash
chown <file> <nuovo-utente-proprietario>
# per esempio
chown file-prova.txt root
```

## I/O Redirection: come passare informazioni attraverso la bash

Tramite l'espressione `>` possiamo sovrascrivere il contenuto di un file 
con l'output di un comando qualsiasi. Per esempio il seguente comando

``` bash
echo "Buongiorno Mondo!" > buongiorno.txt
```

Crea un file txt chiamato `buongiorno.txt` con all'interno il contenuto
della stringa uscita dal comando `echo`

Leggiamo il contenuto del file appena creato con il comando `cat`
``` bash
cat buongiorno.txt
Buongiorno Mondo!
```

Tramite l'espressione `>>` possiamo appendere al contenuto di un file 
con l'output di un comando qualsiasi. Per esempio il seguente comando

``` bash
echo "Buongiorno, mondo" >> buongiorno-2.txt
```

Crea un file txt chiamato `buongiorno-2.txt` con all'interno il contenuto
della stringa uscita dal comando `echo` (se non esiste), altrimenti ne aggiunge
il contenuto in fondo.

Leggiamo il contenuto del file appena creato con il comando `cat`

``` bash
cat buongiorno-2.txt
Buongiorno Mondo!
Buongiorno, mondo
```

Tramite l'espressione `|` possiamo accodare l'output
di un comando come input di un altro comando, vedremo
ora degli esempi

## Creazione di file di script `bash`

Per eseguire più comandi in una volta sola e in maniera sequenziale,
possiamo creare dei file che vengono eseguiti con la `bash`.
Questi file devono avere l'estensione `.sh` e avere come prima riga
il seguente valore:
``` bash
#!/bin/bash
```

Si legge "sharp-bang-bin-bash"

### Passare degli argomenti agli script bash

Possiamo far comportare i nostri script in bash in modo diverso a seconda
di che parametri gli passiamo da fuori. Per farlo, la bash ci fornisce a 
disposizione delle variabili speciali pronte all'uso.

Immaginiamo di avere un file chiamato `mio-script.sh` fatto così

``` bash 
#!/bin/bash
# primo argomento
echo $1 

#secondo argomento
echo $2

# e così via
```

avremmo il seguente output di comando
``` bash
bash mio-file.sh "prova-argomento" "prova-argomento-2"
prova-argomento
prova-argomento-2
```

## Il comando `ps`

Questo comando permette di mostrare tutti i processi attivi nel sistema

``` bash
ps aux
```

## Il comando `grep`

Questo comando permette di vedere se una determinata stringa si trova dentro un altra

``` bash
echo "Bella Ciaone" | grep "Ciaone"
```

Possiamo usarlo in congiunzione con `ps` per cercare determinati processi fra quelli attivi

``` bash
ps aux | grep "bash"
```

## Definizione di variabili in bash

Per definire una variabile in bash basta semplicemente assegnargli un valore, mentre
con `$nome_variabile` possiamo leggere il suo valore

``` bash
# assegno una variabile
miglior_gatto="Maine Coon"

# stampo il valore della variabile
echo "$miglior_gatto"
```

> **NOTA:** Una variabile non assegnata e letta ha valore di stringa vuota (`""`)

## La programmazione condizionale

In questo blocco vedremo come aggiungere blocchi di codice bash, che vengono eseguiti
solo a certe condizioni

``` bash
if [ <condizione> ]; then
    <comandi>
else
    <comandi>
fi
```

### Gli operatori logici

Ecco gli operatori logici, da usare nelle condizioni per metterne più assieme

``` bash
# <condizione_1> AND <condizione_2>
if [ <condizione_1> -a <condizione_2>]; then
    <comandi>
fi

# <condizione_1> OR <condizione_2>
if [ <condizione_1> -o <condizione_2>]; then
    <comandi>
fi

# NOT <condizione_1>
if [ ! <condizione_1> ]; then
    <comandi>
fi
```

### Gli operatori fra stringhe

Questi operatori funzionano **soltanto se `<valore_1>` e
`<valore_2>` sono stringhe di testo**.

``` bash
# valore_1 è uguale a valore_2
if [ <valore_1> == <valore_2> ]; then
    <comandi>
fi

# valore_1 è diverso da valore_2
if [ <valore_1> != <valore_2> ]; then
    <comandi>
fi
```

### Gli operatori matematici

Questi operatori funzionano **soltanto se `<valore_1>` e
`<valore_2>` sono numeri**.

``` bash
# valore_1 è uguale a valore_2
if [ <valore_1> -eq <valore_2> ]; then
    <comandi>
fi

# valore_1 è diverso da valore_2
if [ <valore_1> -neq <valore_2> ]; then
    <comandi>
fi

# valore_1 è maggiore di valore_2
if [ <valore_1> -gt <valore_2> ]; then
    <comandi>
fi

# valore_1 è maggiore o uguale di valore_2
if [ <valore_1> -ge <valore_2> ]; then
    <comandi>
fi

# valore_1 è minore di valore_2
if [ <valore_1> -lt <valore_2> ]; then
    <comandi>
fi

# valore_1 è minore o uguale di valore_2
if [ <valore_1> -le <valore_2> ]; then
    <comandi>
fi

# per esempio
mia_variabile=0
if [ $mia_variabile -lte 0 ]; then
    echo "$mia_variabile è minore o uguale a 0"
fi
```

> Per approfondire: https://tldp.org/LDP/Bash-Beginners-Guide/html/sect_07_01.html

## Eseguire dei cicli in bash

Ora vedremo come eseguire differenti tipi di cicli in bash

### Il ciclo `for`

Questo ciclo viene usato per scorrere una lista di valori

``` bash
lista=( <elementi> )
for element in ${lista[@]}; do
    <comandi>
done

# per esempio

for element in ( "1" "2" "3" ); do
    echo $element
done
```

### Il ciclo `while`

Questo ciclo si interrompe quando la condizione specificata è falsa

``` bash
while <condizione>; do
    <comandi>
done
```

## Le Funzioni in Bash

Le funzioni in Bash sono blocchi di codice riutilizzabili che possono essere chiamati in qualsiasi punto dello script. Sono utili per organizzare il codice, ridurre la duplicazione e migliorare la leggibilità. In questo capitolo, esploreremo come definire, chiamare e utilizzare le funzioni in Bash, insieme a concetti avanzati come il passaggio di parametri e lo scope delle variabili.

### Eseguire operazioni numeriche in Bash

In bash tutto è considerato stringa di default (lo abbiamo visto più volte). Tuttavia è possibile fare calcoli anche con la Bash:

Quello che occorre fare è mettere tali calcoli dentro una area delimitata da `$((<calcoli>))`:

``` bash
#!/bin/bash

a=8
b=3

somma=$((a + b))
differenza=$((a - b))
prodotto=$((a * b))
quoziente=$((a / b))
resto=$((a % b))

echo "Somma: $somma"
echo "Differenza: $differenza"
echo "Prodotto: $prodotto"
echo "Quoziente: $quoziente"
echo "Resto: $resto"

```

### Definizione di una Funzione

Per definire una funzione in Bash, utilizziamo la seguente sintassi:

```bash
nome_funzione() {
    # Comandi della funzione
}
```

Ad esempio:

```bash
#!/bin/bash

saluta_tutti() {
    echo "Halo, everynyan!"
}
```

Per chiamare una funzione, basta scrivere il suo nome:

```bash
#!/bin/bash

saluta_tutti
```

### Passaggio di Parametri

Le funzioni in Bash possono accettare parametri, che vengono passati al momento della chiamata. I parametri sono accessibili all'interno della funzione tramite `$1`, `$2`, ecc...

&Egrave; anche possibile ottenere tutti i parametri in una volta sola, come lista usando `$@`.

```bash
#!/bin/bash

somma() {
    local num1=$1
    local num2=$2

    echo "La somma è: $((num1 + num2))"
}

# Chiamata della funzione con parametri
somma 5 10
```

#### 4. Variabili Locali e Globali

Le variabili definite all'interno di una funzione sono globali per default, ma possono essere rese locali usando `local`.

```bash
#!/bin/bash

VAR_GLOBALE="Globale"

mia_funzione() {
    local VAR_LOCALE="Locale"
    echo "Dentro la funzione: $VAR_LOCALE"
    echo "Dentro la funzione: $VAR_GLOBALE"
}

mia_funzione

echo "Fuori dalla funzione: $VAR_GLOBALE"
echo "Fuori dalla funzione, ma locale: $VAR_LOCALE" # stringa vuota
```

Le funzioni possono includere cicli, condizioni e altre funzioni.

```bash
#!/bin/bash

# Funzione che calcola la somma di una serie di numeri
calcola_somma() {
    local somma=0
    for num in "$@"; do
        somma=$((somma + num))
    done
    echo "La somma totale è: $somma"
}

# Chiamata della funzione con una serie di numeri
calcola_somma 1 2 3 4 5
```

> In bash non esiste la possibilità di restituire valori, però è possibile usare echo per stampare
> e successivamente usare $(...) per acchiappare il valore.
>
> ``` bash
> calcola_somma() {
>     local somma=0
>     for num in "$@"; do
>         somma=$((somma + num))
>     done
>     echo "$somma" # stampiamo con echo
> }
>
> # acchiappiamo con $(...)
> somma_valori=$(calcola_somma 1 2 3 4 5)
> ```
Fanne uno univoco senza cose inutili