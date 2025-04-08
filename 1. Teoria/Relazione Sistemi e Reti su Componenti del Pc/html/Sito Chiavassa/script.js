function mostraConversione() {
    const conversione = `
        <p>1. Parte intera: 160 in binario è 10100000.</p>
        <p>2. Parte decimale: 0,75 in binario è 0,11.</p>
        <p>3. Mantissa: 01000001100000000000000</p>
        <p>4. Esponente (biasato 127): 10000110</p>
        <p>Risultato finale in IEEE754: <strong>0 10000110 01000001100000000000000</strong></p>
    `;
    document.getElementById("conversione").innerHTML = conversione;
}
