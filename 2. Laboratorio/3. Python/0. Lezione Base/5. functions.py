def somma(n1: int, n2: int) -> int:
    """
    Somma due numeri

    Args:
      n1 (int): numero 1
      n2 (int): numero 2
    Returns:
      int: somma
    """
    return n1 + n2


print(somma(1, 2))


def printSomma(n1: int, n2: int) -> int:
    print(somma(n1, n2))
    pass  # Serve quando nelle funzioni che non restituiscono nulla, void.


def numeriPari(lista) -> list:
    pari = []
    for i in lista:
        if i % 2 == 0:
            pari.append(i)
    return pari

#lambda functions --> Vedere listComprehension