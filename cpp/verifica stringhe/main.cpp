#include <iostream>
#include <string>
using namespace std;

int main() {
    string frase, parola;
    cout << "Inserisci la frase: ";
    getline(cin, frase);
    cout << "Inserisci la parola: ";
    getline(cin, parola);

    int i = 0, count = 0;
    bool quattro = false;

        while (i < frase.size()){
            while (i<frase.size()&&((frase.at(i) >= 'a' && frase.at(i) <= 'z') || (frase.at(i) >= 'A' && frase.at(i) <= 'Z'))) {
            i++;
            count++;
               }

        // Se la parola è più lunga di 4 caratteri, inserire la nuova parola
        if (count > 4) {
            quattro = true;
            frase.insert(i, " " + parola); // Inserisce uno spazio e poi la parola
            break; // Uscire dal loop, operazione completata
        }

        else {
            // Resettare il conteggio e passare al prossimo carattere
            count = 0;
            i++;
        }
    }

    if (!quattro) {
        frase += " " + parola;
    }
    cout << "Frase risultante: " << frase << endl;

    return 0;
}
