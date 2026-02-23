n = int(input("Inserisci un numero intero: "))
if n % 2 == 0:
    print(f"Il numero {n} è pari")
elif n % 3 == 0:
    print(f"Il numero {n} è divisibile per 3")
else:
    print(f"Il numero {n} è dispari")

# Metodo figo
#print(f"{n} è {"Pari" if n % 2 == 0 else "Dispari"}")

