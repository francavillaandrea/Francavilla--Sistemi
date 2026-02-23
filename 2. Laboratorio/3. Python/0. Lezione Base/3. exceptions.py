try:
    n = int(input("Inserisci un numero, per favore: "))
except:
    print("Non numero inserito")
else: #Serve a nulla! --> si esegue quando va nell'except
    print("Grazie")
finally:
    print("Sdobberman Finale")
