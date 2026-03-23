# non esiste il do-while

# ma esistono while e for
n = int(input("Inserisci un numero intero: "))

while n % 2 == 0:
    print("Non deve essere pari!")
    n = int(input("Inserisci un numero intero: "))
print("Grazie")

print("Ora li stampiamo tutti")
for i in range(n):
    print(i)

print("---")
for i in range(1, n):
    print(i)

print("---")
for i in range(n - 1, -1, -1):
    print(i)

print("---")
for vowel in "aeiou":
    print(vowel)

print("---")
for i in range(10):
    if i == 5:
        print("Beccato!")
        break
else:
    print("Safe at last")
