# definiamo come lambda una funzione mono-uso che posso 
# anche assegnare a una variabile
#
# Per il resto è UGUALE a una funzione definita con def

isPari = lambda x: x % 2 == 0


def isPari(x: int) -> bool:
    return x % 2 == 0


print(isPari(4))

# Il caso di uso più comune è dentro ai costrutti di aggregazione,
# i più comunemente usati (anche se ce ne sono molti altri!!) sono
# - filter
# - map

listaNumeri = list[int]([1, 2, 3, 4, 5])
listaPari = filter(isPari, listaNumeri)
listaPari = filter(lambda x: x % 2 == 0, listaNumeri)
listaQuadrati = map(lambda x: x ** 2,
                    listaNumeri)  # Prende i valori della lista numeri e li eleva tutti alla seconda, per poi netterli nella lista Quadrati.
print("#"*30)
from functools import reduce

def funzioneDiRiduzione(accumulatore: int, elemento: int) -> int:
    return accumulatore * elemento

somma = reduce(funzioneDiRiduzione, listaNumeri, 0)
print(somma)

print("#"*30)


graaaande_csv = """
nome;cognome;anno_nascita
Aldo;Baglio;01/01/2001
Bruno;Baldoni;02/02/2002
Carlo;Olio;03/03/2003
Mario;Dizio;04/04/2004
"""

#matr = map(lambda line: line.split(";"), graaaande_csv.split("\n"))
