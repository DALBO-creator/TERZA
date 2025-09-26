#include <iostream>
#include <string>
using namespace std;

// Funzione per eliminare tutti i caratteri '1' da una stringa
void elimina_1(string& n) {
    for (int i = 0; i < n.size(); ++i) {
        if (n.at(i) == '1') {
            n.erase(i, 1);
            i--; // Mantieni stabile l'indice
        }
    }
}

// Funzione per contare le occorrenze consecutive di un carattere
int n_occorrenze(char c, const string& s, int i) {
    int count = 0;
    while (i < s.size() && s.at(i) == c) { // Controllo del limite prima
        count++;
        i++;
    }
    return count;
}

// Funzione per eseguire la codifica RLE
string rle(const string& s) {
    string n;
    int i = 0;

    while (i < s.size()) {
        char current = s.at(i);
        int count = n_occorrenze(current, s, i); // Calcola il conteggio una volta

        n += to_string(count); // Aggiungi il conteggio alla stringa codificata
        n += current;          // Aggiungi il carattere corrente
        i += count;            // Salta i caratteri già processati
    }

    elimina_1(n); // Rimuovi tutti i '1' dalla stringa codificata
    return n;
}

int main() {
    string s = "affggg";
    string n = rle(s);
    cout << n << endl; // Output atteso: "a2f3g"
    return 0;
}
