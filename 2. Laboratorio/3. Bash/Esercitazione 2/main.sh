#!/bin/bash

# 1. Rendere il file "main.sh" un file bash eseguibile
chmod a+x main.sh

# 2. Creare la cartella "cartella-esercizio"
mkdir "cartella-esercizio"
# 3. Creare il file "bella-ciaone.txt" dentro la cartella con il contenuto
#    "Bella Ciaone" (in un comando solo)
echo "Bella Ciaone" > "cartella-esercizio/bella-ciaone.txt"
# 4. Dare al file "bella-ciaone.txt" soli permessi di lettura all'utente
#    Tutti gli altri non devono avere nessun permesso, nemmeno il gruppo
chmod 400 "cartella-esercizio/bella-ciaone.txt"
# 5. Mostrare tutti i processi attivi la cui riga comincia con "bash"
ps aux | grep "bash"
# 6. Mostrare questa riga a video, leggendo il file "./main.sh"
cat "main.sh" | grep "# 6."
# 7. Stampare a video l'argomento che viene passato al file "esercizio-02.sh"
echo "$1"