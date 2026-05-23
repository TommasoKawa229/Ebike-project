# Progetto Scolastico: Applicazione Noleggio E-Bike

Il progetto mostrato è un progetto scolastico con indirizzo informatico; lo scopo è di produrre un prototipo per un'applicazione di noleggio di bici elettriche.

## Funzionamento del Sistema
Selezionando un noleggio, il sistema esegue le seguenti operazioni:
1. **Verifica dell'autonomia**: Verifica che l'autonomia residua sia sufficiente per il percorso richiesto.
2. **Calcolo dei parametri**: In caso positivo, calcola il tempo di percorrenza (basato su una velocità media e un ritardo casuale) e il relativo costo del servizio.
3. **Aggiornamento e riepilogo**: Infine, aggiorna l'autonomia della bici scelta e mostra un riepilogo dettagliato della transazione prima di tornare al menu principale.

---

## Analisi Tecnica e Architettura del Codice

### 1. La gestione dei Dati (`Struct`)
L'uso della struct `EBike` è una scelta corretta per aggregare dati di tipo eterogeneo (interi, decimali, booleani).

> 💡 **Evoluzione Futura:** In un'evoluzione orientata agli oggetti (C++ OOP), questa diventerebbe una `class` con attributi privati e metodi getter/setter.

### 2. L'algoritmo di Ordinamento
Hai utilizzato `std::sort` combinato con una funzione di comparazione personalizzata (`confrontoDistanza`).

* **Nota di merito:** Questo dimostra che sai come manipolare gli algoritmi della libreria standard per risolvere problemi logici specifici.
