from flask import Flask, request, render_template_string

app = Flask(__name__)
app.contatore = 0
app.users = {}  # Inizializzato come dizionario per gli IP


@app.route('/')
def saluta():
    return "<h1>Benvenuto su Flask!</h1>"


@app.route('/contatore')
def contatore():
    # Nota: se testi in locale "X-Real-Ip" potrebbe non esserci, usiamo remote_addr come fallback
    ip = request.headers.get("X-Real-Ip", request.remote_addr)

    # Aggiornamento contatori
    app.users[ip] = app.users.get(ip, 0) + 1
    app.contatore += 1

    return f"<h3>Totale visite: {app.contatore}</h3><p>Il tuo IP ({ip}) ha visitato {app.users[ip]} volte.</p>"


@app.route('/ips')
def ips():
    html = "<h1>Lista IP</h1><ul>"
    for ip in app.users.keys():
        html += f"<li>{ip}</li>"
    html += "</ul>"
    return html


@app.route('/classifica')
def classifica():
    ranking_ip = sorted(
        app.users.items(), key=lambda entry: entry[1], reverse=True
    )
    html = "<h1>Classifica Accessi</h1><ul>"
    for ip, clicks in ranking_ip:
        html += f"<li><strong>{ip}</strong>: {clicks} click</li>"
    html += "</ul>"
    return html


# --- NUOVA ROUTE PER HTTP.CAT ---
@app.route('/status/<int:code>')
def show_cat(code):
    """
    Prende un codice numerico dall'URL e restituisce la foto del gatto.
    Esempio: http://127.0.0.1:6767/status/404
    """
    cat_url = f"https://http.cat/{code}"

    # Usiamo un template string per semplicità, ma l'ideale sarebbe un file .html
    html_template = f"""
    <!DOCTYPE html>
    <html>
    <head>
        <title>Status {code}</title>
    </head>
    <body>
        <h1>Status Code: {code}</h1>
        <img src="{cat_url}" alt="HTTP Cat {code}">
    </body>
    </html>
    """
    return render_template_string(html_template)


@app.route("/pastebin", methods=["POST"])
def create_bin():
    # Esempio: ricevi dati e conferma
    body = request.data.decode('utf-8')
    return f"Bin creato con successo: {body[:20]}..."


if __name__ == '__main__':
    # Usiamo 0.0.0.0 per rendere il server accessibile nella rete locale
    app.run(port=6767, debug=True)