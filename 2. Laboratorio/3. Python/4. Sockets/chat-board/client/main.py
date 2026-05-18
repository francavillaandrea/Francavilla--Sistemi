from UDPChatClient import UDPChatClient

def main():

    print(f"Inserire l'indirizzo IP del server: ", end="")
    ip_address = input()

    print(f"inserisci un nome: ", end="")
    name = input()

    client = UDPChatClient(ip_address, name)
    
    try:
        client.join()

        while True:
            print("> ", end="")
            message = input().strip()
            client.send_message(message)
    except Exception as e:
        print("Errore", e)
    finally:
        client.leave()


if __name__ == "__main__":
    main()
