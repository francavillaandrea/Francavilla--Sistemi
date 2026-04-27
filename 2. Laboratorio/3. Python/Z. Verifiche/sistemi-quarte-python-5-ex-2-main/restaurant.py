from threading import Lock
class Customer:
    """Represents a customer of the restaurant."""

    name: str
    """The name of the customer."""

    def __init__(self, name: str):
        self.name = name

    def __str__(self) -> str:
        return self.name

class Dish:
    """Represents a dish of the restaurant."""

    name: str
    """The name of the dish."""

    def __init__(self, name: str):
        """Initializes a dish with the given name."""
        self.name = name

    def __str__(self) -> str:
        """Returns a string representation of the dish."""
        return self.name

class Order:
    """Represents an order of the restaurant."""

    customer: Customer
    """The customer who made the order."""

    dishes: list[Dish]
    """The dishes that were ordered."""

    def __init__(self, customer: Customer, dishes: list[Dish]):
        """Initializes an order with the given customer and dishes."""
        self.customer = customer
        self.dishes = dishes

    def __str__(self) -> str:
        """Returns a string representation of the order."""
        return f"{self.customer} ordered {', '.join(str(dish) for dish in self.dishes)}"

class Cook:
    """Represents a cook of the restaurant."""

    name: str
    """The name of the cook."""

    # TODO: add other attributes here if needed
    orders: list[Order] # Corretto da orders: list
    """The list of orders to cook."""

    ordersLock: Lock
    """Lock for thread-safe access to orders."""

    def __init__(self, name: str, orders: list[Order], ordersLock: Lock): #COrrezione di orders da orders:list[Orderx]  # TODO: add other parameters here if needed
        """Initializes a cook with the given name, orders list and lock."""
        self.name = name
        self.orders = orders
        self.ordersLock = ordersLock

    def __str__(self) -> str:
        """Returns a string representation of the cook."""
        return self.name

    def cook(self) -> None:
        """Cooks the dishes of the order."""
        order = None  # TODO: add correct order here from queue
        if self.ordersLock.acquire(timeout=5):
            if self.orders:
                order = self.orders.pop(0)
            self.ordersLock.release()

        if order is not None:
            print(f"{self} is cooking {order}")


class Waiter:
    """Represents a waiter of the restaurant."""

    name: str
    """The name of the waiter."""

    # TODO: add other attributes here if needed
    orders: list[Order]
    """The list of orders taken by the waiter."""

    ordersLock: Lock
    """Lock for thread-safe access to orders."""

    def __init__(self, name: str, orders: list[Order], ordersLock: Lock):  # TODO: add other parameters here if needed
        """Initializes a waiter with the given name, orders list and lock."""
        self.name = name
        self.orders = orders
        self.ordersLock = ordersLock

    def __str__(self) -> str:
        """Returns a string representation of the waiter."""
        return self.name

    def take_order(self, customer: Customer, dishes: list[Dish]) -> None:
        """Takes an order from a customer."""
        order = Order(customer=customer, dishes=dishes)

        # TODO: add order to queue here
        if self.ordersLock.acquire(timeout=5):
            self.orders.append(order)
            self.ordersLock.release()
        print(f"{self} took the order from {customer}")
