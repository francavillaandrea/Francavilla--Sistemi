fibo_maccio = [ 0, 1, 1, 2, 3, 5, 8, 13 ]

print(f"Singolo elemento: {fibo_maccio[0]}")
print(f"Lista intera: {fibo_maccio}")
print(f"Sotto lista: {fibo_maccio[1:5]}")
print(f"Sotto lista: {fibo_maccio[:5]}")
print(f"Sotto lista: {fibo_maccio[2:]}")
print(f"Sotto lista: {fibo_maccio[2:-2]}")

fibo_clone = fibo_maccio[:]
fibo_clone[3] = 1000
print(f"Lista clonata: {fibo_clone}")

print(f"Lista ordinata: {sorted(fibo_maccio)}")

print(f"Lista invertita: {fibo_maccio[::-1]}")
# print(f"Lista invertita: {reversed(fibo_maccio)}")

print(f"Lista stringata: {str(fibo_maccio)}")

