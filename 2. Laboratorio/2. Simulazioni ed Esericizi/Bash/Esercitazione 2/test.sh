# Non usare questo file per la consegna, questo file non deve essere
# modificato

# NON TOCCARE QUESTI COMANDI!!!
find . -type f -not -name '*.sh' -and -not -name "*replit*" -and -not -wholename ".*" -delete || true
rm -rf cartella-esercizio || true

echo "Scrivi una riga per specificare degli argomenti, o premi invio"
read "LINE" || true

bash "./esercizio-2.sh" "$LINE"

[[ $(cat './esercizio-2.sh') == "#!/bin/bash"* ]] || echo "Error: 1"
ls | grep "cartella-esercizio" || echo "Error: 2"

cat "cartella-esercizio/bella-ciaone.txt" || echo "Error: 3"
ls -l "cartella-esercizio/bella-ciaone.txt" | grep -- "$SECRET_2" || echo "Error: 4"
