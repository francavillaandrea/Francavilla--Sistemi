n = int(input("Inserisci un numero intero in input: "))

# otteniamo tutti i numeri pari da 0 a n
pari = list[int]()
for i in range(n):
    if i % 2 == 0:
        pari.append(i)
print(pari)

pari = list[int]()
for i in range(0, n, 2):
    pari.append(i)
print(pari)

pari = [ number for number in range(n) if number % 2 == 0 ]
pari = [ number for number in range(0, n, 2) ]

