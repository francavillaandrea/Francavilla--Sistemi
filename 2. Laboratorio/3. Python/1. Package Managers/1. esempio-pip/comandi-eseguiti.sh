mkdir 1-esempio-pip
cd 1-esempio-pip
touch main.py # e riempire
echo ".venv" > .gitignore # per non committare environment
python -m venv .venv # crea virtualenv
source .venv/bin/activate # attiva virtualenv
python main.py # mi aspetto errore "requests" non è installato
pip install requests
python main.py # funziona