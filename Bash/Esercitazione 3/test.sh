#!/bin/bash

# Non usare questo file per la consegna, questo file non deve essere
# modificato

# NON TOCCARE QUESTI COMANDI!!!

echo "Inserisci un valore numerico per iniziare:"
read LINE || true

if [ -z "$LINE" ]; then
    echo "Errore: la stringa non può essere vuota!"
    exit 1
fi

project_root=$(pwd)

. ./main.sh "$LINE"

cd $project_root

if [ -z ${my_directory+x} ]; then
    echo "2. La variabile \"my_directory\" non è impostata"
else
    echo "2. La variabile \"my_directory\" è impostata"
fi

if [ -d "$my_directory" ]; then
    echo "2. La cartella \"$my_directory\" è stata creata"
else 
    echo "2. La cartella \"$my_directory\" non è stata creata"
fi

if [ -z ${number_list+x} ]; then
    echo "4. La variabile \"number_list\" non è impostata"
else
    echo "4. La variabile \"number_list\" è impostata"
fi

rm -rf "$my_directory"

exit 0
