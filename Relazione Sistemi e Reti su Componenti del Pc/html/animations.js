// animations.js

// Funzione per animare le carte nella pagina index
function animateCards() {
    const cards = document.querySelectorAll('.card');
    
    cards.forEach((card, index) => {
        setTimeout(() => {
            card.style.opacity = '0';
            card.style.transform = 'translateY(20px)';
            card.style.transition = 'opacity 0.5s ease, transform 0.5s ease';
            
            setTimeout(() => {
                card.style.opacity = '1';
                card.style.transform = 'translateY(0)';
            }, 100);
        }, index * 200);
    });
}

// Funzione per animare le sezioni con fade-in e slide-in
function animateSections() {
    const sections = document.querySelectorAll('h1, h2, p, ul, ol');
    
    sections.forEach((section, index) => {
        section.style.opacity = '0';
        section.style.transform = 'translateY(20px)';
        section.style.transition = 'opacity 0.5s ease, transform 0.5s ease';
        
        setTimeout(() => {
            section.style.opacity = '1';
            section.style.transform = 'translateY(0)';
        }, index * 100);
    });
}

// Funzione per animare il clock e gli elementi nella pagina clock
function animateClock() {
    const clockTick = document.getElementById('clockTick');
    let degree = 0;

    setInterval(() => {
        clockTick.textContent = degree % 360 < 180 ? 'Tick' : 'Tock';
        clockTick.style.transform = `rotate(${degree}deg)`;
        degree += 6;
    }, 50);

    animateSections(); // Riutilizziamo la funzione per gli altri elementi
}

// Funzione per animare la chiusura della pagina
function animateExit() {
    const elements = document.querySelectorAll('h1, h2, p, ul, ol, .card');
    elements.forEach((el) => {
        el.style.opacity = '0';
        el.style.transform = 'translateY(-20px)';
        el.style.transition = 'opacity 0.3s ease, transform 0.3s ease';
    });
}

// Funzione principale per inizializzare le animazioni
function initAnimations() {
    const currentPage = document.body.id;

    switch(currentPage) {
        case 'index-page':
            animateCards();
            break;
        case 'cpu-page':
        case 'componenti-page':
        case 'vonneumann-page':
            animateSections();
            break;
        case 'clock-page':
            animateClock();
            break;
        default:
            console.log('No specific animations for this page');
            animateSections(); // Fallback animation for any unspecified page
    }
}

// Esegui le animazioni quando il DOM è completamente caricato
document.addEventListener('DOMContentLoaded', initAnimations);

// Aggiungi animazione di chiusura quando la pagina sta per essere lasciata
window.addEventListener('beforeunload', animateExit);