#include <iostream>
#include <string>

// Funzione per verificare se un carattere è già presente nella stringa
bool presente(char c, const std::string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

// Funzione principale per rimuovere i duplicati
std::string uniciCaratteri(const std::string& o) {
    std::string s; // Stringa risultato

    for (int i = 0; i < o.size(); i++) { // Ciclo con indice
        if (!presente(o[i], s)) {
            s += o[i]; // Aggiungi solo se non è già presente
        }
    }
    return s;
}

int main() {
    // Stringa di test
    std::string o = "BBello questo corso di Informatica";
    std::string s = uniciCaratteri(o);

    // Stampa i risultati
    std::cout << "Stringa originale: " << o << std::endl;
    std::cout << "Stringa risultante: " << s << std::endl;

    return 0;
}
