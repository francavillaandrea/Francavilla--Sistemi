# Esercizio 2: Threads e Locks in Python 3

> Tempo per svolgere l'esercizio: 45 minuti
>
> Suggerimento: cercate i commenti TODO nel codice per capire cosa va completato.

Benvenuti al ristorante "Magnamobbene"! In questo esercizio, implementeremo una semplice simulazione di un ristorante con clienti, camerieri e cuochi. L'obiettivo è quello di gestire correttamente l'accesso alle risorse condivise (ordini) utilizzando i thread e i lock in Python.

Il vostro obiettivo è completare il codice fornito in `main.py` e `restaurant.py` per garantire che gli ordini vengano gestiti in modo sicuro, senza conflitti o condizioni di gara (e non rimangano eternamente bloccati in attesa).

> Leggete attentamente i commenti nel codice e seguite le istruzioni per completare l'implementazione.
>
> Il codice attuale non funziona, va completato per farlo funzionare correttamente.

# Idea generale

- I camerieri raccolgono gli ordini dai clienti e li aggiungono alla coda delle comande.
- I cuochi preparano le comande in coda uno alla volta.

e così via...

> Ribadiamo che le comande sono IN CODA.
>
> Qualsiasi cuoco può preparare qualsiasi comanda in coda, ma solo un cuoco alla volta può prendere una comanda dalla coda.
>
> Qualsiasi cameriere può aggiungere una comanda alla coda, ma solo un cameriere alla volta può farlo.