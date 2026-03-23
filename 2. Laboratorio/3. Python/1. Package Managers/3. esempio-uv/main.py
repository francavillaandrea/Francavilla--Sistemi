import requests

def main():
    result = requests.get("https://jsonplaceholder.typicode.com/todos/1")
    
    print(result.json())

if __name__ == "__main__":
    main()
