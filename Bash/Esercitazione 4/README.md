[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=16640140)
# Sistemi e Reti - Classi Terze - Bash - Esercitazione 4

In questa esercitazione andremo a scoprire più dettagli sullo scope delle variabili e
impareremo a creare funzioni riutilizzabili per i nostri script.

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