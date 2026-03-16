import requests

results = requests.get("https://jsonplaceholder.typicode.com/todos/1")

print(results.json())