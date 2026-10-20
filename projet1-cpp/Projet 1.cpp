#include <iostream>
#include <cstdlib>
#include <conio.h>

enum class TileType {
    Basicground,
    Water,
    Mountain,
    Hero,
    Ennemy

};

struct Map {
    char Basicground = '.';
    char Water = '~';
    char Mountain = 'A';
    char Hero = 'H';
    char Ennemy = 'X';
};


struct Hero {
    int x = 0;
    int y = 0;
    int hp = 1;
};
struct Ennemy {
    int x = 0;
    int y = 0;
    int hp = -1;
};

bool est_traversable(int x, int y, const Map& map) {       //Collision
    // basicground
    if (x < 0 || x >= 20 || y < 0 || y >= 10) return false;

    // Water
   if ((y == 1 && x >= 5 && x <= 8) ||
        (y == 2 && x >= 5 && x <= 8) ||
        (y == 6 && (x == 16 || x == 17)))

    return false;
   // Moutain
    if ((y == 2 && x >= 12 && x <= 14) ||
         (y == 6 && x >= 2 && x <= 4)) 
        return false;
}

void deplacer_hero(Hero& hero, char direction, Map& map) {
    int nx = hero.x;
    int ny = hero.y;

    if (direction == 'z' || direction == 'Z') ny--;
    if (direction == 's' || direction == 'S') ny++;
    if (direction == 'q' || direction == 'Q') nx--;
    if (direction == 'd' || direction == 'D') nx++;

    // Collision avec les bordures de la carte
    if (est_traversable(nx, ny, map)) {
        hero.x = nx;
        hero.y = ny;
    }
};


void afficher_map(const Map& map, const Hero& hero) {

    system("cls");

    int grille[10][20] = {};

    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 20; ++x) {
            grille[y][x] = map.Basicground;
        }
    }

    for (int x = 5; x <= 8; ++x) {
        grille[1][x] = map.Water;
        grille[2][x] = map.Water;
    }
    grille[6][16] = map.Water;
    grille[6][17] = map.Water;

    for (int x = 12; x <= 14; ++x) {
        grille[2][x] = map.Mountain;
    }
    for (int x = 2; x <= 4; ++x) {
        grille[6][x] = map.Mountain;
    }

    grille[hero.y][hero.x] = map.Hero;

    grille[4][10] = map.Ennemy;
    grille[7][12] = map.Ennemy;
    grille[3][5] = map.Ennemy;
    grille[8][2] = map.Ennemy;
    grille[8][7] = map.Ennemy;
    

    for (int ligne = 0; ligne < 10; ++ligne) {
        for (int colonne = 0; colonne < 20; ++colonne) {
            if (grille[ligne][colonne] != (map.Water)
                && grille[ligne][colonne] != (map.Mountain)
                && grille[ligne][colonne] != (map.Hero)
                && grille[ligne][colonne] != (map.Ennemy )) {
               grille[ligne][colonne] = map.Basicground;
            }

            std::cout << static_cast<char>(grille[ligne][colonne]); //<< ' ';
           //std::cout << grille[ligne][colonne] << ' ';

            grille[hero.y][hero.x] = map.Hero;
        }
        std::cout << '\n';
    }
}
void death(Hero& hero, Ennemy& ennemy) {
    int death;
    death = hero.hp;
        if (death == 0) 

    std::cout << "Game Over" << '\n';
    
}






int main() {
    Map map{};
    Hero hero{};
    Ennemy ennemy{};
    //Gameover (map, hero, ennemy );
    char commande = ' ';


    while (commande != 'e') { // 'e' pour quitter
        afficher_map(map, hero);
        std::cout << "Deplacement (Z = haut, Q = gauche, S = bas, D = droite, E = quitter) : ";
        commande = _getch();

        deplacer_hero(hero, commande, map);
    }
}




