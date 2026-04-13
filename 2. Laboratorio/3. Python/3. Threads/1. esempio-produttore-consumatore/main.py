from threading import Lock, Thread

def thread1_deadlock(A: Lock, B: Lock):
    """
    Questa versione soffre di deadlock con thread2: non avendo un timeout
    Quando thread1 ottiene A e thread2 ottiene B il sistema si blocca
    """
    i : int = 0

    while True:
        A.acquire()
        B.acquire()

        print(f"Thread 1: {i}")
        i = i + 1

        B.release()
        A.release()

def thread2_deadlock(A: Lock, B: Lock):
    """
    Questa versione soffre di deadlock con thread1: non avendo un timeout
    Quando thread1 ottiene A e thread2 ottiene B il sistema si blocca
    """
    i : int = 0

    while True:
        B.acquire()
        A.acquire()

        print(f"Thread 2: {i}")
        i = i + 1

        A.release()
        B.release()

def thread1_timeout(A: Lock, B: Lock):
    """
    Questa versione non soffre di deadlock con thread2: avendo un timeout
    Quando thread1 ottiene A e thread2 ottiene B il sistema si blocca, ma solo temporaneamente.
    Questo elimina il deadlock ma introduce livelock e starvation.
    """
    i : int = 0

    while True:
        # Se io non riesco a ottenere sia A che B, rilascio A e riprovo
        # provo al max per 1 secondi, se non riesco restituisce False
        if A.acquire(timeout=1): 
            if B.acquire(timeout=1):
                print(f"Thread 1: {i}")
                i = i + 1

                B.release()
            A.release()

def thread2_timeout(A: Lock, B: Lock):
    """
    Questa versione non soffre di deadlock con thread2: avendo un timeout
    Quando thread1 ottiene A e thread2 ottiene B il sistema si blocca, ma solo temporaneamente.
    Questo elimina il deadlock ma introduce livelock e starvation.
    """
    i : int = 0

    while True:
        if B.acquire(timeout=1):
            if A.acquire(timeout=1):
                print(f"Thread 2: {i}")
                i = i + 1

                A.release()
            B.release()

def main():
    A = Lock()
    B = Lock()

    thread1 = Thread(target=thread1_timeout, args=(A, B))
    thread2 = Thread(target=thread2_timeout, args=(A, B))

    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()


if __name__ == "__main__":
    main()
