#include <iostream>

struct Map {
    char Basicground = '.';
    char Water = '~';
    char Mountain = 'A';
    char Hero = 'H';
};

struct Hero {

    int hp = 1;
    
};


void afficher_map(const Map& map) {

    char grille[10][20] = {};

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

    grille[0][0] = map.Hero;


    for (int ligne = 0; ligne < 10; ++ligne) {
        for (int colonne = 0; colonne < 20; ++colonne) {
            if (grille[ligne][colonne] != (map.Water) && grille[ligne][colonne] != (map.Mountain) && grille[ligne][colonne] != (map.Hero)) {
                grille[ligne][colonne] = map.Basicground;
            }

            std::cout << grille[ligne][colonne] << ' ';
        }
        std::cout << '\n';
    }
}


int main() {
    Map map{};
    Hero hero{};
    afficher_map(map);

   
    int x = 0;
    int y = 0;


    char H; 
    

    std::cout << "Deplacement : Z Q S D" ;

    std::cin >> H;

    if (H == 'z') y++;
    if (H == 's') y--;
    if (H == 'q') x--;
    if (H == 'd') x++;

    std::cout << "Position : " << x << ", " << y  ;

    return 0;

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