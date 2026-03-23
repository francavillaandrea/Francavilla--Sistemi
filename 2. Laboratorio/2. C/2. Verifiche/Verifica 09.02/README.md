# Esercitazione 6 - Le strutture dati in C

![Set Pic](.lesson/assets/set.png)

In questa esercitazione occorre implementare tutte le funzioni definite nei file `node.h` e `set.h`.

> Il file `testing.h` è una libreria necessaria per i test, non dovete toccarla.
>
> Questo progetto è compatibile sia con l'IDE CLion che con l'IDE Code::Blocks
>
> Per usare questo progetto offline, naturalmente dovete prima scaricarlo da REPLit
>
> Se usate CLion, aprite il file `Makefile` con Clion (Apri con -> Clion)
>
> Se usate Code::Blocks, aprite il file con estensione `.cbp`

Gli unici files che verranno corretti sono il file `node.h` e il file `set.h`.

Le funzioni da implementare sono di 5 tipi su 1 entità:

- costruzione di entità (ovvero la creazione di entità a partire da certi parametri)
- clonazione di entità (ovvero la creazione di una nuova entitò a partire da un'altra)
- distruzione di entità (ovvero la deallocazione completa di una entità)
- inserimento univoco in un insieme
- operazioni di routine su insiemi (controllo elementi, rimozione, ottenimento dimensione, etc...)

Si ricorda che un insieme (Set) contiene solo valori univoci, e non è detto che sia per forza ordinato.

> In questa implementazione il set è ordinato!

Qui c'è l'elenco completo dei test:

```
reateNode(...)
  createNode("0")
  createNode("1")
  createNode("2")
  createNode("3")
  createNode("4")

cloneNode(...)
  cloneNode(NULL)
  cloneNode(temp) - Test 0
  cloneNode(temp) - Test 1
  cloneNode(temp) - Test 2
  cloneNode(temp) - Test 3
  cloneNode(temp) - Test 4

destroyNode(...)
  destroyNode(NULL)
  destroyNode(node)
  destroyNode(node) - de-allocation

createEmptySet(...)
  createEmptySet()

cloneSet(...)
  cloneSet(NULL)
  cloneSet(empty_list)
  cloneSet(list) - Test 0
  cloneSet(list) - Test 1
  cloneSet(list) - Test 2
  cloneSet(list) - Test 3
  cloneSet(list) - Test 4

destroySet(...)
  destroySet(NULL)
  destroySet(empty_list)
  destroySet(list) - Test 0
  destroySet(list) - Test 1
  destroySet(list) - Test 2
  destroySet(list) - Test 3
  destroySet(list) - Test 4

getSetSize(...)
  getSetSize(NULL)
  getSetSize(empty_list)
  getSetSize(list) - Test 1
  getSetSize(list) - Test 2
  getSetSize(list) - Test 3

setContains(...)
  setContains(NULL, "1")
  setContains(empty_list, "1")
  setContains(list, "4") - Test 1
  setContains(list, "2") - Test 1
  setContains(list, "1") - Test 1
  setContains(list, "3") - Test 1
  setContains(list, "4") - Test 2
  setContains(list, "2") - Test 2
  setContains(list, "1") - Test 2
  setContains(list, "3") - Test 2
  setContains(list, "4") - Test 3
  setContains(list, "2") - Test 3
  setContains(list, "1") - Test 3
  setContains(list, "3") - Test 3

insertNodeInSet(...)
  insertNodeInSet(NULL, "1", 1)
  insertNodeInSet(set, "1", -1)
  insertNodeInSet(set, "1", 5)
  insertNodeInSet(set, "1", 5) - already present
  insertNodeInSet(set, "2", 5)
  insertNodeInSet(set, "2", 1) - already present
  insertNodeInSet(set, "3", 0)
  insertNodeInSet(set, "3", 3) - already present

printSet(...)
  printSet(NULL)
  printSet(empty_list)
  printSet(list)
```

## FAQ

### Non vedo tutti i test, come mai?

I test compariranno man mano che implementate correttamente le funzioni.

### Devo preoccuparmi di deallocare correttamente?

I test controllano anche la memoria allocata, quindi si.

### Posso modificare altri file a parte `node.h` e `set.h`?

No.