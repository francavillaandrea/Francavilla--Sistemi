n = int(input("Inserisci un numero intero: "))

if n % 2 == 0:
    print(f"{n} è pari")
elif n % 3 == 0:
    print(f"{n} è dispari e divisibile per 3")
else:
    print(f"{n} è dispari")
# oppure
# print(f"{n} è {"pari" if n % 2 == 0 else "dispari"}")
