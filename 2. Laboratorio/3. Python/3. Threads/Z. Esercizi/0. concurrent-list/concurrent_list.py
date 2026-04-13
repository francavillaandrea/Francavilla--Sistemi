from threading import Lock
import time


class ConcurrentList:
    def __init__(self, maxsize: int = 0) -> None:
        self.list = []
        self.lock = Lock()

    def append(self, value) -> None:
        self.lock.acquire()
        try:
            self.list.append(value)
        finally:
            self.lock.release()

    def pop(self):
        while True:
            self.lock.acquire()
            try:
                if self.list:
                    return self.list.pop()
            finally:
                self.lock.release()
            time.sleep(0.001)

    def qsize(self) -> int:
        self.lock.acquire()
        try:
            return len(self.list)
        finally:
            self.lock.release()

    def empty(self) -> bool:
        self.lock.acquire()
        try:
            return len(self.list) == 0
        finally:
            self.lock.release()
