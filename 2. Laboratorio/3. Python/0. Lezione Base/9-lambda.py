squared = lambda x: x * x

print(squared(2))

lista = [1, 2, 3, 4, 5]
print(list(filter(lambda n: n > 3, lista))) # filter, filtra su lambda

lista_doppi = map(lambda n: n * 2, lista) # map: modifica con lambda 
                                          #e restituisce copia

