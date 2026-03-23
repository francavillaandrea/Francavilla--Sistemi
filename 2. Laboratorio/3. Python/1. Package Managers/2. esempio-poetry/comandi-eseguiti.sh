pip install poetry # da fuori virtualenv
poetry new 2-esempio-poetry
cd 2-esempio-poetry
# copiare il main di esempio in src/--/__init__.py
poetry add requests
poetry env activate #attiviamo il virtualenv
python src/2_esempio_poetry/__init__.py #funziona