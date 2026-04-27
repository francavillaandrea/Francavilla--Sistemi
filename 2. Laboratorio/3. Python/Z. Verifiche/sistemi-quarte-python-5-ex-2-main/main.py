import random
from threading import Lock, Thread
from time import sleep
from restaurant import Customer, Dish, Order, Cook, Waiter


def new_customer() -> Customer:
    """Generates a new customer."""
    names = ["Alice", "Bob", "Charlie", "Dave", "Eve", "Frank", "Grace", "Heidi", "Ivan", "Judy", "Karl", "Leo", "Mallory", "Nina", "Oscar", "Peggy", "Quentin", "Rupert", "Sybil", "Trent"]

    customer = Customer(name=random.choice(names))
    print(f"New customer arrived: {customer}")

    return customer

def waiter_work(waiter: Waiter):
    """Simulates the work of a waiter."""
    menu = [ Dish(name=name) for name in ["Pizza", "Pasta", "Salad", "Soup", "Burger", "Fries", "Steak", "Fish", "Chicken", "Sushi"] ]

    while True:
        waiter.take_order(customer=new_customer(), dishes=random.sample(menu, k=random.randint(1, 3)))

        sleep(random.randint(1, 3))

def cook_work(cook: Cook) -> None:
    """Simulates the work of a cook."""
    while True:
        cook.cook()

        sleep(random.randint(1, 3))

def main():
    orders: list[Order] = []

    # TODO: add other variables if needed
    lock: Lock = Lock()

    waiters = [
        Waiter(name = "Aldo", orders = orders, lock = lock),# Corretto
        Waiter(name = "Giovanni", orders = orders, lock = lock),# Corretto
        Waiter(name = "Giacomo", orders = orders, lock = lock) # Corretto
    ]

    cooks = [
        Cook(name = "Mario", orders = orders,lock = lock),# Corretto
        Cook(name = "Luigi", orders = orders,lock = lock),# Corretto
        Cook(name = "Maria", orders = orders,lock = lock),# Corretto
        Cook(name = "Giulia", orders = orders,lock = lock),# Corretto
        Cook(name = "Francesca", orders = orders,lock = lock),# Corretto
        Cook(name = "Grazia", orders = orders,lock = lock),# Corretto
    ]

    # TODO: start threads for waiters and cooks here
    threadsWaiters = [Thread(target=waiter_work, args=(waiter,), daemon=True) for waiter in waiters] # Daemon = true serve a far si che il main possa uscire a cnhe quando i thread figli del main non hanno effettuato alcuna azione
    threadsCooks = [Thread(target=cook_work, args=(cook,), daemon=True) for cook in cooks] #

    totThreads = threadsWaiters + threadsCooks

    for thread in totThreads:
        thread.start()

    try:
        for thread in totThreads:
            thread.join()
    except:
        pass
    finally:
        print("\nRestaurant closed!")

if __name__ == "__main__":
    main()
