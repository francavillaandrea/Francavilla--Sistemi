person = ("Alessandro", "Sanino")
lista = ["Alessandro", "Sanino"]
print(lista[0])
print(person[0])

person = ("ASD", "Sanino")

lista = list(person)
print(lista)
stringa = str().join(lista)
print(stringa)
lista = list(stringa)

print(lista)