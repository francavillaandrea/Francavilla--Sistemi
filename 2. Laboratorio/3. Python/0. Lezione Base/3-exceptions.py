try:
    n = int(input("Inserisci un numero, per favore: "))
except ValueError:
    print("Sei proprio malvagio")
else:
    print("Grazie")
finally:
    print("Veramente")