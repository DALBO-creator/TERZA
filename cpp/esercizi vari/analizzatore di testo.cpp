#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Funzione per leggere tutto il file in un vettore di parole
vector<string> leggiParole(const string& nomeFile) {
    ifstream in(nomeFile);
    vector<string> parole;
    if (!in) {
        cout << "Errore: impossibile aprire il file.\n";
        return parole;
    }
    string parola;
    while (in >> parola) {
        parole.push_back(parola);
    }
    return parole;
}

// Conta i caratteri (inclusi spazi e punteggiatura)
long contaCaratteri(const string& nomeFile) {
    ifstream in(nomeFile);
    if (!in) return 0;
    long count = 0;
    char c;
    while (in.get(c)) count++;
    return count;
}

// Conta le frasi basandosi su '.', '?', '!'
int contaFrasi(const string& nomeFile) {
    ifstream in(nomeFile);
    if (!in) return 0;
    int frasi = 0;
    char c;
    while (in.get(c)) {
        if (c == '.' || c == '?' || c == '!') frasi++;
    }
    return frasi;
}

// Trova la parola più lunga
string parolaPiuLunga(const vector<string>& parole) {
    string max = "";
    for (size_t i = 0; i < parole.size(); i++) {
        if (parole[i].size() > max.size())
            max = parole[i];
    }
    return max;
}

// Trova la parola più frequente (senza map)
string parolaFrequente(const vector<string>& parole) {
    string maxParola;
    int maxConteggio = 0;

    for (size_t i = 0; i < parole.size(); i++) {
        int conteggio = 0;
        for (size_t j = 0; j < parole.size(); j++) {
            if (parole[i] == parole[j]) conteggio++;
        }
        if (conteggio > maxConteggio) {
            maxConteggio = conteggio;
            maxParola = parole[i];
        }
    }
    return maxParola;
}

// Stampa un report completo
void stampaReport(const string& file,
                  const vector<string>& parole,
                  long caratteri,
                  int frasi) {
    cout << "\n===== ANALISI TESTO =====\n";
    cout << "File: " << file << "\n";
    cout << "Caratteri: " << caratteri << "\n";
    cout << "Parole: " << parole.size() << "\n";
    cout << "Frasi: " << frasi << "\n";

    if (!parole.empty()) {
        string lunga = parolaPiuLunga(parole);
        string frequente = parolaFrequente(parole);
        cout << "Parola piu' lunga: " << lunga
             << " (" << lunga.size() << " caratteri)\n";
        cout << "Parola piu' frequente: " << frequente << "\n";
    }
    cout << "=========================\n";
}

// Menu semplice
void menu() {
    cout << "\n=== ANALIZZATORE DI TESTO ===\n";
    cout << "1) Analizza un file\n";
    cout << "0) Esci\n";
    cout << "Scelta: ";
}

int main() {
    int scelta;
    string nomeFile;

    do {
        menu();
        cin >> scelta;

        if (scelta == 1) {
            cout << "Nome del file: ";
            cin >> nomeFile;

            vector<string> parole = leggiParole(nomeFile);
            long caratteri = contaCaratteri(nomeFile);
            int frasi = contaFrasi(nomeFile);

            if (!parole.empty() || caratteri > 0) {
                stampaReport(nomeFile, parole, caratteri, frasi);
            } else {
                cout << "Il file e' vuoto o non leggibile.\n";
            }
        } else if (scelta != 0) {
            cout << "Scelta non valida.\n";
        }
    } while (scelta != 0);

    cout << "Chiusura programma.\n";
    return 0;
}
