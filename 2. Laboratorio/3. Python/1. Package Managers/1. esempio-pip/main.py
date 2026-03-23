import requests

result = requests.get("https://jsonplaceholder.typicode.com/todos/1")

print(result.json())
