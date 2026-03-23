# 0: input di una lista di interi, separati da una virgola. dentro una lista
def input_csv():
    line = input().split(",")

    return [int(x) for x in line]

# lista_numeri = input_csv()

# 1. come esercizio 0 ma in una riga
# lista_numeri = [int(x) for x in input().split(",")]
lista_numeri = list[int](map(int, input().split(",")))

# 2. dei numeri in input, ottenere la sola lista dei numeri primi
def is_prime(n):
    if (n == 2):
        return True
    for x in range (3, n / 2 + 1, 2):
        if (n % x == 0):
            return False
    else:
        return True

lista_primi = filter(is_prime, lista_numeri)

# 3. come 2 ma in una riga
lista_primi = list(filter(lambda x : all(lambda p : p % x != 0, range(2, x / 2)), lista_numeri))