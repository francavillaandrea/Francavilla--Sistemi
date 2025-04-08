[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=16718703)
# Sistemi e Reti - Classi Terze - Bash - Lezione 2

In questa esercitazione impareremo a padroneggiare dei nuovi concetti:
- I permessi di file e cartelle in un ambiente UNIX
- I/O Redirection: come passare informazioni attraverso la bash
- Creazione di file di script bash

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
