[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=16718702)
# Sistemi e Reti - Classi Terze - Bash - Lezione 3

In questa esercitazione impareremo a padroneggiare dei nuovi concetti:
- Definizione di variabili in bash
- I costrutti `if`, `then`, `else` e `fi` per la programmazione condizionale
- Esecuzione di cicli (`while`, `do`, `done`, `for`)

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
