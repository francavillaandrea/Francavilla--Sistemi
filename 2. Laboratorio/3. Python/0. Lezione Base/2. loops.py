# Non esiste il post condizionale

n = int(input("Inserisci un numero intero: "))

while n % 2 == 0:
    print("Non deve essere pari!")
    n = int(input("Inserisci un numero intero: "))
print("Grazie")

print("Ora li stampiamo tutti")
for i in range(n):
    print(i)

for i in range(1, n):
    print(i)

for i in range(n - 1, 0, -1):
    print(i)

print("-" * 20)
for vowel in "aeiou":
    print(vowel)

print("-" * 20)
for i in range(10):
    if i == 8:
        print("Beccato!")
        break
else:
    print("Non deve essere pari!")

