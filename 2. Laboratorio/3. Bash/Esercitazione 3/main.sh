#!/bin/bash

# 1. Leggere dal primo argomento un valore numerico, se questo valore è maggiore 
#    o uguale a 18, stampare a video la scritta "Sei maggiorenne", altrimenti la 
#    scritta "Sei minorenne"
numeric_value="$1"
if [ "$numeric_value" -ge "18" ]; then
    echo "Sei maggiorenne"
else
    echo "Sei minorenne"
fi

# 2. Creare una variabile "my_directory" con all'interno il valore
#    "./mia-cartella-<numero_input>" 
#    e creare la cartella in questione usando la variabile nel comando
my_directory="./mia-cartella-$numeric_value"
mkdir "$my_directory"

# 3. Se il nome della cartella è uguale a
#    "./mia-cartella-18" 
#    stampare a video
#    "La cartella \"<valore-variabile>\" è di un maggiorenne"
#    altrimenti stampare a video 
#    "La cartella \"<valore-variabile>\" è di un minorenne"
if [ "$my_directory" == "./mia-cartella-18" ]; then
    echo "La cartella \"$my_directory\" è di un 18enne"
else 
    echo "La cartella \"$my_directory\" non è di un 18enne"
fi

# 4. Assegnare a una variabile "number_list" i valori della seguente lista
#    1 2 3 5 8 13 21 34 55
#    e stampare l'intera lista a video, scorrendola
number_list=( 1 2 3 5 8 13 21 34 55 )
for element in ${number_list[@]}; do
    echo $element
done
