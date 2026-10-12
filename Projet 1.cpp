#include <iostream>

struct Map {
    char Basicground = '.';
    char Water = '~';
    char Mountain = 'A';
};

struct Hero {

    int hp = 1;
    char body = 'H';
};

void afficher_map(const Map& map) {

    char grille[10][20] = {};

    grille[5][6] = map.Water;
    grille[5][7] = map.Water;
    grille[9][2] = map.Mountain;

    for (int ligne = 0; ligne < 10; ++ligne) {
        for (int colonne = 0; colonne < 20; ++colonne) {
            if (grille[ligne][colonne] != (map.Water) && grille[ligne][colonne] != (map.Mountain)) {
                grille[ligne][colonne] = map.Basicground;
            }
            
            std::cout << grille[ligne][colonne] << ' ';
        }
        std::cout << '\n';
    }
}


int main() {
    Map map{};
    afficher_map(map);




}




/*int main()

{
    char grille[10][21] = { 
        {'.', '.', '.', '.', '.', '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
        {'.', '.', '.', '.', '.', '~', '~', '~', '~', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '~', '~', '~', '~', '.', '.', '.', 'A', 'A', 'A', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.', '.', '.', '.', '.', '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.', '.', '.', '.', '.', '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.', '.', '.', '.', '.', '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.', '.', 'A', 'A', 'A', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '~', '~', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.', '.', '.', '.', '.', '.', '.','.','.','.','.','.','.','.','.','.','.','.','.','.'},

    };
    for (int ligne = 0; ligne < 10; ++ligne) {
        for (int colonne = 0; colonne < 20; ++colonne) {
            std::cout << grille[ligne][colonne] << ' ';
        }
        std::cout << '\n';

    }
}*/

