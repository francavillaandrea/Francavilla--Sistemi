# definiamo come lambda una funzione mono-uso che posso 
# anche assegnare a una variabile
#
# Per il resto è UGUALE a una funzione definita con def

is_pari = lambda x : x % 2 == 0

#def is_pari(x: int) -> bool:
#    return x % 2 == 0

print(is_pari(4))

# Il caso di uso più comune è dentro ai costrutti di aggregazione,
# i più comunemente usati (anche se ce ne sono molti altri!!) sono
# - filter
# - map

lista_numeri = list[int]([1, 2, 3, 4, 5, 6])
lista_pari = filter(is_pari, lista_numeri) # 2 4 6
# lista_pari = filter(lambda x: x % 2 == 0, lista_numeri) # 2 4 6
lista_quadrati = map(lambda x: x ** 2, lista_numeri) # 1 4 9 16 25 36

# ----------

from functools import reduce

def funzione_di_riduzione(accumulatore: int, elemento: int) -> int:
    return accumulatore + elemento

somma = reduce(lambda acc, x: acc + x, lista_numeri, 0)

# ----------


'''
graaaande_csv = """
nome;cognome;anno_nascita
Aldo;Baglio;01/01/2001
Bruno;Baldoni;02/02/2002
Carlo;Olio;03/03/2003
Mario;Dizio;04/04/2004
"""

matr = map(lambda line: line.split(";"), graaaande_csv.split("\n"))
'''
