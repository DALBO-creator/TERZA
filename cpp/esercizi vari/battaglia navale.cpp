#include <iostream>
#include <ctime>    // per time()
#include <cstdlib>  // per rand() e srand()

using namespace std;

const int DIM = 5;    // dimensione della griglia (5x5)
const int NAVI = 3;   // numero di navi

// Inizializza la griglia con '~'
void inizializzaGriglia(char griglia[DIM][DIM]) {
    for (int r = 0; r < DIM; r++)
        for (int c = 0; c < DIM; c++)
            griglia[r][c] = '~';
}

// Stampa la griglia senza mostrare le navi
void stampaGriglia(const char griglia[DIM][DIM]) {
    cout << "   ";
    for (int c = 0; c < DIM; c++) cout << c << " ";
    cout << "\n";
    for (int r = 0; r < DIM; r++) {
        cout << r << " |";
        for (int c = 0; c < DIM; c++) {
            char ch = griglia[r][c];
            if (ch == 'N') ch = '~';   // nasconde le navi
            cout << ch << " ";
        }
        cout << "\n";
    }
}

// Posiziona casualmente le navi
void posizionaNavi(char griglia[DIM][DIM]) {
    int piazzate = 0;
    while (piazzate < NAVI) {
        int r = rand() % DIM;
        int c = rand() % DIM;
        if (griglia[r][c] == '~') {
            griglia[r][c] = 'N';
            piazzate++;
        }
    }
}

// Gestisce il tiro
bool spara(char griglia[DIM][DIM], int r, int c) {
    if (r < 0 || r >= DIM || c < 0 || c >= DIM) {
        cout << "Coordinate fuori griglia!\n";
        return false;
    }
    if (griglia[r][c] == 'N') {
        griglia[r][c] = 'X';
        cout << "Colpito!\n";
        return true;
    }
    if (griglia[r][c] == '~') {
        griglia[r][c] = 'O';
        cout << "Acqua...\n";
        return false;
    }
    cout << "Hai già provato qui!\n";
    return false;
}

int main() {
    char griglia[DIM][DIM];
    srand(time(0)); // inizializza il generatore di numeri casuali

    inizializzaGriglia(griglia);
    posizionaNavi(griglia);

    cout << "=== BATTAGLIA NAVALE ===\n";
    cout << "Griglia " << DIM << "x" << DIM << ", " << NAVI << " navi da affondare.\n\n";

    int colpite = 0;
    while (colpite < NAVI) {
        stampaGriglia(griglia);

        int r, c;
        cout << "Inserisci riga e colonna (0-" << DIM-1 << "): ";
        cin >> r >> c;

        if (spara(griglia, r, c)) {
            colpite++;
            cout << "Navi colpite: " << colpite << "/" << NAVI << "\n";
        }
    }

    cout << "\nComplimenti! Hai affondato tutte le navi!\n";
    return 0;
}
