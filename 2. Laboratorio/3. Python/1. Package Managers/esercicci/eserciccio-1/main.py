import requests
import os
import csv

def main():
    todos = requests.get("https://jsonplaceholder.typicode.com/todos").json()
    users = requests.get("https://jsonplaceholder.typicode.com/users").json()

    completed = 0
    for todo in todos:
        if todo.completed:
            completed = completed + 1
    print(f"Completed: {completed}, Not completed: {len(todos) - completed}")

    with os.open("file.csv", 0, 600) as file:
        with csv.writer(file) as writer:
            map(lambda todo: writer.writerow(todo), todos)

    





if __name__ == "__main__":
    main()
