#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Libro {
    string titolo;
    string autore;
    string anno;
    string isbn;
    int copie;
    int prestiti;
};

void nuovo_libro(vector<Libro>& libri) {
    Libro libro;
    cout << "Titolo: ";
    cin.ignore();
    getline(cin, libro.titolo);
    cout << "Autore: ";
    getline(cin, libro.autore);
    cout << "Anno: ";
    getline(cin, libro.anno);
    cout << "ISBN: ";
    getline(cin, libro.isbn);
    cout << "Copie: ";
    cin >> libro.copie;
    libro.prestiti = 0;
    libri.push_back(libro);
}

void elenco(const vector<Libro>& libri) {
    for (int i = 0; i < libri.size(); i++) {
        cout << "Libro numero " << i + 1 << ":\n";
        cout << "Titolo: " << libri[i].titolo << endl;
        cout << "Autore: " << libri[i].autore << endl;
        cout << "Anno: " << libri[i].anno << endl;
        cout << "ISBN: " << libri[i].isbn << endl;
        cout << "Copie disponibili: " << libri[i].copie << endl;
        cout << "Prestiti totali: " << libri[i].prestiti << endl;
        cout << "--------------------\n";
    }
}

void simula_prestito(vector<Libro>& libri, int& prestiti_tot) {
    if (libri.empty()) {
        cout << "Nessun libro disponibile per il prestito.\n";
        return;
    }
    int indice = rand() % libri.size();
    if (libri[indice].copie > 0) {
        libri[indice].copie--;
        libri[indice].prestiti++;
        prestiti_tot++;
    } else {
        cout << "Copie del libro numero " << indice + 1 << " esaurite.\n";
    }
}

void cerca_by_isbn(const vector<Libro>& libri) {
    string isbn;
    cout << "ISBN da cercare: ";
    cin.ignore();
    getline(cin, isbn);
    for (int i = 0; i < libri.size(); i++) {
        if (libri[i].isbn == isbn) {
            cout << "Libro trovato:\n";
            cout << "Titolo: " << libri[i].titolo << endl;
            cout << "Autore: " << libri[i].autore << endl;
            cout << "Anno: " << libri[i].anno << endl;
            cout << "ISBN: " << libri[i].isbn << endl;
            cout << "Copie disponibili: " << libri[i].copie << endl;
            cout << "Prestiti totali: " << libri[i].prestiti << endl;
        }
    }
}

void cerca_by_parola(const vector<Libro>& libri) {
    string parola;
    cout << "Parola da cercare nel titolo: ";
    cin.ignore();
    getline(cin, parola);
    for (int i = 0; i < libri.size(); i++) {
        if (libri[i].titolo.find(parola) != string::npos) {
            cout << "Libro numero " << i + 1 << ":\n";
            cout << "Titolo: " << libri[i].titolo << endl;
            cout << "Autore: " << libri[i].autore << endl;
            cout << "Anno: " << libri[i].anno << endl;
            cout << "ISBN: " << libri[i].isbn << endl;
            cout << "Copie disponibili: " << libri[i].copie << endl;
            cout << "Prestiti totali: " << libri[i].prestiti << endl;
            cout << "--------------------\n";
        }
    }
}

void elenco_abbreviato(const vector<Libro>& libri) {
    for (int i = 0; i < libri.size(); i++) {
        cout << "Libro numero " << i + 1 << ":\n";
        if (libri[i].titolo.size() > 10) {
            cout << "Titolo: " << libri[i].titolo.substr(0, 10) << "...\n";
        } else {
            cout << "Titolo: " << libri[i].titolo << endl;
        }
        cout << "Autore: " << libri[i].autore << endl;
        cout << "Anno: " << libri[i].anno << endl;
        cout << "ISBN: " << libri[i].isbn << endl;
        cout << "Copie disponibili: " << libri[i].copie << endl;
        cout << "Prestiti totali: " << libri[i].prestiti << endl;
        cout << "--------------------\n";
    }
}

void modifica_anno(vector<Libro>& libri) {
    string isbn, anno;
    cout << "ISBN del libro da modificare: ";
    cin.ignore();
    getline(cin, isbn);
    cout << "Nuovo anno: ";
    getline(cin, anno);
    for (int i = 0; i < libri.size(); i++) {
        if (libri[i].isbn == isbn) {
            libri[i].anno = anno;
            cout << "Anno modificato con successo.\n";
        }
    }
}

int main() {
    vector<Libro> libri;
    int prestiti_tot = 0, scelta;

    do {
        cout << "\nMenu:\n";
        cout << "0) Esci dal programma\n";
        cout << "1) Aggiungi un nuovo libro\n";
        cout << "2) Elenca tutti i libri\n";
        cout << "3) Simula un prestito casuale\n";
        cout << "4) Cerca un libro per ISBN\n";
        cout << "5) Cerca un libro per parola nel titolo\n";
        cout << "6) Elenco abbreviato dei libri\n";
        cout << "7) Modifica l'anno di un libro\n";
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 0:
                cout << "Uscita dal programma.\n";
                break;
            case 1:
                nuovo_libro(libri);
                break;
            case 2:
                elenco(libri);
                break;
            case 3:
                simula_prestito(libri, prestiti_tot);
                if (prestiti_tot >= 20) {
                    cout << "Sono state effettuate 20 operazioni di prestito. Il programma si chiude.\n";
                    scelta = 0;
                }
                break;
            case 4:
                cerca_by_isbn(libri);
                break;
            case 5:
                cerca_by_parola(libri);
                break;
            case 6:
                elenco_abbreviato(libri);
                break;
            case 7:
                modifica_anno(libri);
                break;
            default:
                cout << "Scelta non valida. Riprova.\n";
        }
    } while (scelta != 0);

    return 0;
}
