#include <bits/stdc++.h>

#include "include/raylib.h"

void inizializza(const std::string &segreta, std::string& attuale) {
    attuale = "";
    for (int i = 0; i < segreta.size(); ++i) {
        attuale += '_';
    }
}

bool controlla(const std::string& segreta, char lettera,
    std::string &attuale) {
    bool trovata = false;
    for (int i = 0; i < segreta.size(); ++i) {
        if (segreta.at(i) == lettera) {
            attuale.at(i) = lettera;
            trovata = true;
        }
    }
    return trovata;
}

std::string lettere_usate(const std::string& provate) {
    std::string s;
    for (int i = 0; i < provate.size(); ++i) {
        s += provate.at(i);
        s += ", ";
    }
    return s;
}

void disegna(const Texture &immagine, int errori) {
    DrawTexture(immagine, 0, 0, WHITE);
    int w = immagine.width;
    int h = immagine.height;
    for (int i = errori; i < 9; ++i) {
        DrawRectangle((i % 3) * (w / 3), (i / 3) * (h / 3), w / 3, h/3, WHITE);
    }
}

std::vector<std::string> carica_parole(const std::string& path) {
    std::vector<std::string> parole;
    std::string parola;
    std::ifstream in(path);

    if (in) {
        while (in >> parola) {
            parole.push_back(parola);
        }
        if (parole.empty()) {
            std::cout << "Errore apertura file";

        }
    }
    return parole;
}

int main(void)
{
    srand(time(NULL));
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    const int MAX_ERRORI = 9;
    int conta_errori = 0;
    int stato = 0;
    std::string provate, attuale;

    std::string segreta;
    std::string vinto = "Hai vinto!";
    std::string perso = "Hai perso!";

    std::vector<std::string> parole = carica_parole("../assets/parole.txt");
    segreta = parole.at(rand() % parole.size());
    inizializza(segreta, attuale);

    InitWindow(screenWidth, screenHeight, "Attento al mostro");

    Texture2D mostro = LoadTexture("../assets/mostro.png");

    if (mostro.id == 0) {
        std::cout << "Errore: Immagine non caricata correttamente!" << std::endl;
        return 1;
    }

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        char lettera = GetCharPressed();
        if (lettera > 0) {
            std::cout << lettera;
            if (!controlla(segreta, lettera, attuale)) {
                conta_errori++;
            }
            if (segreta == attuale) {
                stato = 1;
            }
            if (conta_errori == MAX_ERRORI) {
                stato = 2;
            }
        }


        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        switch (stato) {
            case (0) : {
                disegna(mostro, conta_errori);
                DrawText(attuale.c_str(), 20, 350, 60, BLACK);
                break;
            }
            case (1) : {
                DrawText(vinto.c_str(), 20, 350, 60, BLACK);
                break;
            }
            case (2) : {
                DrawText(perso.c_str(), 50, 70, 60, BLACK);
                DrawText("La parola segreta era: ", 50, 210, 60, BLACK);
                DrawText(segreta.c_str(), 50, 280, 60, BLACK);
                break;
            }
            default : {
                break;
            }
        }



        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
