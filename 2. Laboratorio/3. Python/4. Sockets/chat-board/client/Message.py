import json

class Message:
    def __init__(self, name=None, content=None):
        self.name = name
        self.content = content

    def serialize(self):
        data = {
            "name": self.name,
            "content": self.content
        }
        return json.dumps(data).encode("utf-8")

    @staticmethod
    def deserialize(data_bytes):
        """@staticmethod: metodo che NON usa 'self', richiamabile direttamente
        dalla classe senza creare istanze."""
        data = json.loads(data_bytes.decode("utf-8"))
        return Message(data["name"], data["content"])
