def somma(n1 : int, n2 : int) -> int: 
    """
    Somma due numeri.

    Args:
      n1 -> int: il primo numero
      n2 -> int: il secondo numero
    Returns:
      int -> la somma dei 2 numeri
    """
    return n1 + n2

print(somma(1, 2))

def print_somma(n1: int, n2: int):
    print(somma(n1, n2))

def numeri_pari(lista: list) -> list:
    pari = []

    for numero in lista:
        if numero % 2 == 0:
            pari.append(numero)

    return pari

# lambda functions (vedere 6-list-comprehension)