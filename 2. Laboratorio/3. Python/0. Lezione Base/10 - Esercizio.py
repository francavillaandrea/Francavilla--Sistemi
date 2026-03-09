# 0: Input di una lista di interi, separati da una virgola, dentro una lista
def inputCsv():
    line = input().split('\n')
    return [int(x) for x in line]


listaNumeri = inputCsv()

# 1. come esercizio 0 ma in una riga

outputList: list[int] = list[int](map(int, input("Insersci lista").split(",")))
print(outputList)


# 2. Prendiamo questa lista e filtriamo solò numeri primi inline
def is_prime(n):
    return n > 1 and all(n % i != 0 for i in range(2, int(n ** 0.5) + 1))

listPrimi

print(listPrimi)
