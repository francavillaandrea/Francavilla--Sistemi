import time
import asyncio

"""
Questa è una funzione "sincrona"

sincrono => che segue le logiche di sincronizzazione della CPU
         => sequenziale
"""
def sync_function(value: str):
    time.sleep(1)
    print(value)

sync_function("ciao")
sync_function("o")
sync_function("o")
sync_function("o")

"""
Funzione asincrona: viene eseguita "in parallelo"
quindi non c'è mai garanzia di ordine se viene richiamata in
sequenza.
"""
async def async_function(value: str):
    # la parola chiave await "aspetta che una funzione async termini"
    await asyncio.sleep(1)
    print(value)

from random import random, randint

async def dynamic_wait(i):
    slippo = randint(1, 4)
    await asyncio.sleep(slippo)
    print(f"{i}: wewe -> {slippo}")

async def main(): # serve un main async per gestire logiche async
    # non c'è alcuna garanzia che stampi
    # 1 2 3 4 in questo ordine
    await asyncio.gather(
        dynamic_wait(1),
        dynamic_wait(2),
        dynamic_wait(3),
        dynamic_wait(4),
    )


# se sono nel main e non sto importando questo file
if __name__ == "__main__":
    asyncio.run(main()) # abilito la concorrenza
