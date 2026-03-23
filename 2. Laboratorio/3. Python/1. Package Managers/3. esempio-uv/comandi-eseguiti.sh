curl -LsSf https://astral.sh/uv/install.sh | sh # installare uv
uv init 3-esempio-uv # inizializza un nuovo progetto
cd 3-esempio-uv
# copiare il main.py
uv run main.py # errore "requests" non installato
uv add requests
uv run main.py # funziona
