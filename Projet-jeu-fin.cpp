#include <iostream>
#include <cstdlib>
#include <conio.h>

enum class Map_symbol {
    Basicground = '.',
    Water = '~',
    Mountain = 'A',
    Hero = 'H',
    Ennemy = 'X',
    Exit = 'E'
};

struct Hero {
    int x = 0;
    int y = 0;
};

const int ligne = 20;
const int colonne = 10;

int niveau = 1;

Map_symbol grille[colonne][ligne];

bool est_traversable(int x, int y) {
    if (x < 0 || x >= ligne || y < 0 || y >= colonne)
        return false;

    Map_symbol symbol = grille[y][x];
    if (symbol == Map_symbol::Water || symbol == Map_symbol::Mountain)
        return false;

    return true;
}

void deplacer_ennemis(int ennemis[][2], int nb_ennemis) {
    for (int i = 0; i < nb_ennemis; ++i) {
        int nx = ennemis[i][0];
        int ny = ennemis[i][1];

        int random_direction = rand() % 4;

        if (random_direction == 0) ny--;
        else if (random_direction == 1) ny++;
        else if (random_direction == 2) nx--;
        else nx++;

        if (est_traversable(nx, ny)) { 
            ennemis[i][0] = nx;
            ennemis[i][1] = ny;
        }
    }
}

bool est_touche_par_ennemis(const Hero& hero, int ennemis[][2], int nb_ennemis) {
    for (int i = 0; i < nb_ennemis; ++i) {
        if (hero.x == ennemis[i][0] && hero.y == ennemis[i][1])
            return true;
    }
    return false;
}

void deplacer_hero(Hero& hero, char direction) {
    int nx = hero.x;
    int ny = hero.y;

    if (direction == 'z' || direction == 'Z') ny--;
    if (direction == 's' || direction == 'S') ny++;
    if (direction == 'q' || direction == 'Q') nx--;
    if (direction == 'd' || direction == 'D') nx++;

    if (est_traversable(nx, ny)) {
        hero.x = nx;
        hero.y = ny;
    }
}

void afficher_map(const Hero& hero, int ennemis[][2], int nb_ennemis) {
    system("cls");

    for (int y = 0; y < colonne; ++y)
        for (int x = 0; x < ligne; ++x)
            grille[y][x] = Map_symbol::Basicground;

    if (niveau == 1) {
        for (int x = 5; x <= 8; ++x) {
            grille[1][x] = Map_symbol::Water;
            grille[2][x] = Map_symbol::Water;
        }
        grille[6][18] = Map_symbol::Water;
        grille[6][17] = Map_symbol::Water;

        for (int x = 12; x <= 14; ++x)
            grille[2][x] = Map_symbol::Mountain;
        for (int x = 2; x <= 4; ++x)
            grille[6][x] = Map_symbol::Mountain;
    }

    if (niveau == 2) {
        for (int x = 5; x <= 9; ++x) {
            grille[4][x] = Map_symbol::Water;
            grille[5][x] = Map_symbol::Water;
        }
        grille[8][11] = Map_symbol::Water;
        grille[8][12] = Map_symbol::Water;

        for (int x = 12; x <= 14; ++x)
            grille[5][x] = Map_symbol::Mountain;
        for (int x = 2; x <= 4; ++x)
            grille[3][x] = Map_symbol::Mountain;
    }

    grille[9][19] = Map_symbol::Exit;


    for (int i = 0; i < nb_ennemis; ++i) {
        int ex = ennemis[i][0];
        int ey = ennemis[i][1];
        if (ey >= 0 && ey < colonne && ex >= 0 && ex < ligne
            && grille[ey][ex] != Map_symbol::Exit) {
            grille[ey][ex] = Map_symbol::Ennemy;
        }
    }

    for (int y = 0; y < colonne; ++y) {
        for (int x = 0; x < ligne; ++x) {
            if (x == hero.x && y == hero.y)
                std::cout << static_cast<char>(Map_symbol::Hero);
            else
                std::cout << static_cast<char>(grille[y][x]);
        }
        std::cout << '\n';
    }
}

int main() {
    Hero hero{ 0, 0 };
    char commande = ' ';

    const int nb_ennemis = 5;
    int ennemis[nb_ennemis][2] = {
        {10, 4},
        {12, 7},
        {5, 3},
        {2, 8},
        {7, 8}
    };

    bool jeu_en_cours = true;

    while (commande != 'e' && commande != 'E' && jeu_en_cours) {
        afficher_map(hero, ennemis, nb_ennemis);
        std::cout << "Deplacement (Z = haut, Q = gauche, S = bas, D = droite, E = quitter) : ";
        commande = _getch();

        deplacer_hero(hero, commande);

        if (grille[hero.y][hero.x] == Map_symbol::Exit) {
            if (niveau == 1) {
                niveau = 2;
                hero.x = 0;
                hero.y = 0;
                std::cout << "\nNIVEAU 1 TERMINE ! Ta cru que c'etait fini?\n";
                std::cout << "Appuie sur une touche";
                _getch();
            }
            else {
                afficher_map(hero, ennemis, nb_ennemis);
                std::cout << "\nVICTOIRE ! T'es chaud!\n";
                jeu_en_cours = false;
            }
            
        }
        deplacer_ennemis(ennemis, nb_ennemis);

        if (est_touche_par_ennemis(hero, ennemis, nb_ennemis)) {
            afficher_map(hero, ennemis, nb_ennemis);
            std::cout << "T'a perdu";
            jeu_en_cours = false;
        }
    }
    return 0;
}