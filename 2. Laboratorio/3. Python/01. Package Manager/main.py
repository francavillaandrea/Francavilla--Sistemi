import requests
import csv


def main():
    # 1. Scarico i dati
    todos = requests.get("https://jsonplaceholder.typicode.com/todos").json()
    users = requests.get("https://jsonplaceholder.typicode.com/users").json()

    # 2. Analisi
    completed_todos = [t for t in todos if t['completed']]
    # Cerchiamo sia nel nome (Name) che nello username per sicurezza
    users_with_f = [u for u in users if u['name'].lower().startswith('f')]

    print(f"Total Todos completati: {len(completed_todos)}")
    print(f"Utenti il cui nome inizia per 'F': {len(users_with_f)}")

    # 3. Esportazione CSV (Solo i Todos, come richiesto)
    if todos:
        keys = todos[0].keys()
        with open('tutti_i_todos.csv', 'w', newline='', encoding='utf-8') as csvfile:
            writer = csv.DictWriter(csvfile, fieldnames=keys)
            writer.writeheader()
            # Scriviamo TUTTI i todos (non solo quelli completati)
            writer.writerows(todos)

        print("File 'tutti_i_todos.csv' creato con successo!")


if __name__ == '__main__':
    main()