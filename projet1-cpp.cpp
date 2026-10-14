#include <iostream>
#include <cstdlib>
#include <conio.h>

/*enum class TileType {
    Basicground,
    Water,
    Mountain,
    Hero
};*/

struct Map {
    char Basicground = '.';
    char Water = '~';
    char Mountain = 'A';
    char Hero = 'H';
};


struct Hero {
    int x = 0;
    int y = 0;
    int hp = 1;
    
};

void deplacer_hero(Hero& hero, char direction) {
    int nx = hero.x;
    int ny = hero.y;

    if (direction == 'z' || direction == 'Z') ny--;
    if (direction == 's' || direction == 'S') ny++;
    if (direction == 'q' || direction == 'Q') nx--;
    if (direction == 'd' || direction == 'D') nx++;

    // Collision avec les bordures de la carte
    if (nx >= 0 && nx < 20 && ny >= 0 && ny < 10) {
        hero.x = nx;
        hero.y = ny;
    }
};

enum class TileType {
    Basicground,
    Water,
    Mountain,
    Hero
};
//enum
void afficher_map(const Map& map, const Hero& hero) {

    system("cls");

    int grille[10][20] = {};
    
    grille[1][5] = map.Water;
    grille[1][6] = map.Water;
    grille[1][7] = map.Water;
    grille[1][8] = map.Water;
    grille[2][5] = map.Water;
    grille[2][6] = map.Water;
    grille[2][7] = map.Water;
    grille[2][8] = map.Water;
    grille[6][17] = map.Water;
    grille[6][16] = map.Water;

    grille[2][12] = map.Mountain;
    grille[2][13] = map.Mountain;
    grille[2][14]= map.Mountain;
    grille[6][2] = map.Mountain;
    grille[6][3] = map.Mountain;
    grille[6][4] = map.Mountain;

    grille[hero.y][hero.x] = map.Hero;


    for (int ligne = 0; ligne < 10; ++ligne) {
        for (int colonne = 0; colonne < 20; ++colonne) {
            if (grille[ligne][colonne] != (map.Water) && grille[ligne][colonne] != (map.Mountain) && grille[ligne][colonne] != (map.Hero)) {
                grille[ligne][colonne] = map.Basicground;
            }

            std::cout << static_cast<char>(grille[ligne][colonne]) << ' ';
            //std::cout << grille[ligne][colonne] << ' ';

            grille[hero.y][hero.x] = map.Hero;

            



                }
                std::cout << '\n';
            }
        }
    


    int main() {
        Map map{};
        Hero hero{};
        char commande = ' ';


        while (commande != 'e') { // 'e' pour quitter
            afficher_map(map, hero);
            std::cout << "Deplacement (Z = haut, Q = gauche, S = bas, D = droite, E = quitter) : ";
            commande = _getch();

            deplacer_hero(hero, commande);
        }
    }
       
     
    

  

