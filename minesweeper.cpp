#include "minesweeper.h"

int main(int argc, char* argv[])
{
    if(argc != 4){
        std::cout << "usage: ./minesweeper [x size] [y size] [mine count]\n";
        exit(1);
    }

    int x_size = std::atoi(argv[1]);
    int y_size = std::atoi(argv[2]);
    int mine_count = std::atoi(argv[3]);

    if(mine_count >= (x_size * y_size)){
        std::cout << "too many mines.\n";
        exit(1);
    }
    else if(x_size <=0 || y_size <=0 || mine_count <= 0){
        std::cout << "one or more inputs are too small.\n";
        exit(1);
    }
    else if(x_size >99 || y_size > 99)
    {
        std::cout << "one or more inputs are too large. (limit 99)\n";
        exit(1);
    }

    //-------------------------------------------------------------------------

    grid g = grid(x_size, y_size, mine_count);

    g.print_grid();
    int x, y;

    while(1)
    {
        std::cout << "coords: x y\n> ";
        std::cin >> x;
        std::cin >> y;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10, '\n');
            //get data, ignore errors
        }
        else
        {
            g.reveal(x, y);
        }

        g.print_grid();
    }

    return(0);
}
