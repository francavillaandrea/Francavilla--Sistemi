fibonacci = [0, 1, 1, 2, 3, 5, 8, 13]
print(f"Singolo elemento: {fibonacci[0]}")
print(f"Intera Lista: {fibonacci}")
print(f"Sotto Lista: {fibonacci[1:5]}")
print(f"Sotto Lista: {fibonacci[:5]}")
print(f"Sotto Lista: {fibonacci[2:]}")
print(f"Sotto Lista: {fibonacci[2: -2]}")

fiboClone = fibonacci[:]
print(f"Fibonacci Clonata: {fiboClone}")

print(f"Lista Ordinata: {sorted(fiboClone)}")

print(f"Lista Invertita: {fiboClone[::-1]}")
#print(f"Lista Invertita: {reversed(fiboClone)}")
