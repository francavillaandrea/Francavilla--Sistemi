# questo è un commento, non verrà interpretato e puoi usarlo per aggiungere note

# 1. stampa a video la stringa "Bella Ciaone"
echo "Bella Ciaone"
# 2. Crea il file "test.txt" vuoto
touch "test.txt"
# 3. Copia il file vuoto in un nuovo file "test-2.txt"
cp "test.txt" "test-2.txt"
# 4. Rinomina il file "test-2.txt" in "test-renamed-2.txt"
mv "test-2.txt" "test-renamed-2.txt"
# 5. Rimuovi il file "test-renamed-2.txt"
rm "test-renamed-2.txt"
# 6. Crea la directory "mia-cartella" all'interno della cartella dove ti trovi
mkdir "mia-cartella"
# 7. Rimuovi la cartella "mia-cartella"
rmdir "mia-cartella"
# 8. Crea la directory "mia-cartella" all'interno della cartella "./mia-cartella-2" e rendila la tua working directory
mkdir -p "mia-cartella-2/mia-cartella"
cd "mia-cartella-2/mia-cartella"
