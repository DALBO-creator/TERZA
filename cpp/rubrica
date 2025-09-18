#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Contatto {
    string nome;
    string numero;
};

// Mostra tutti i contatti
void mostraRubrica(const vector<Contatto>& rubrica) {
    if (rubrica.empty()) {
        cout << "Rubrica vuota.\n";
        return;
    }
    cout << "\n--- RUBRICA ---\n";
    for (size_t i = 0; i < rubrica.size(); i++) {
        cout << i + 1 << ") " << rubrica[i].nome
             << " - " << rubrica[i].numero << "\n";
    }
    cout << "----------------\n";
}

// Aggiunge un nuovo contatto
void aggiungiContatto(vector<Contatto>& rubrica) {
    Contatto c;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, c.nome);
    cout << "Numero: ";
    getline(cin, c.numero);
    rubrica.push_back(c);
    cout << "Contatto aggiunto!\n";
}

// Cerca un contatto per nome
void cercaContatto(const vector<Contatto>& rubrica) {
    string nome;
    cout << "Inserisci il nome da cercare: ";
    cin.ignore();
    getline(cin, nome);

    bool trovato = false;
    for (const auto& c : rubrica) {
        if (c.nome == nome) {
            cout << "Trovato: " << c.nome << " - " << c.numero << "\n";
            trovato = true;
        }
    }
    if (!trovato) cout << "Nessun contatto trovato.\n";
}

// Elimina un contatto
void eliminaContatto(vector<Contatto>& rubrica) {
    mostraRubrica(rubrica);
    if (rubrica.empty()) return;

    int indice;
    cout << "Inserisci il numero dell'elenco da eliminare: ";
    cin >> indice;
    if (indice > 0 && indice <= (int)rubrica.size()) {
        rubrica.erase(rubrica.begin() + (indice - 1));
        cout << "Contatto eliminato.\n";
    } else {
        cout << "Indice non valido.\n";
    }
}

int main() {
    vector<Contatto> rubrica;
    int scelta;

    do {
        cout << "\n=== RUBRICA TELEFONICA ===\n";
        cout << "1) Mostra contatti\n";
        cout << "2) Aggiungi contatto\n";
        cout << "3) Cerca contatto\n";
        cout << "4) Elimina contatto\n";
        cout << "0) Esci\n";
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1: mostraRubrica(rubrica); break;
            case 2: aggiungiContatto(rubrica); break;
            case 3: cercaContatto(rubrica); break;
            case 4: eliminaContatto(rubrica); break;
            case 0: cout << "Chiusura rubrica.\n"; break;
            default: cout << "Scelta non valida.\n";
        }
    } while (scelta != 0);

    return 0;
}
