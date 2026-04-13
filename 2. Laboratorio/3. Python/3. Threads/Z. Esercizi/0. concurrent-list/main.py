from string import ascii_letters
from random import randint
from threading import Thread

from concurrent_list import ConcurrentList


def random_string(n: int = 10) -> str:
    """
    Genera una stringa casuale di n lettere
    """
    return str([ascii_letters[randint(0, len(ascii_letters) - 1)] for i in range(n)])


def producer(i: int, list: ConcurrentList):
    while True:
        value = random_string()
        list.append(value)

        print(f"Producer {i} -> {value}")


def consumer(i: int, list: ConcurrentList):
    while True:
        try:
            value = list.pop()
            print(f"Consumer {i} <- {value}")
        finally:
            pass


def main():
    list = ConcurrentList()

    producers = [
        Thread(target=producer, args=(i, list)) for i in range(3)
    ]

    consumers = [
        Thread(target=consumer, args=(i, list)) for i in range(5)
    ]

    threads = producers + consumers

    for thread in threads:
        thread.start()

    for thread in threads:
        thread.join()


if __name__ == "__main__":
    main()
