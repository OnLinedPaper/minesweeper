class grid
{
    public:
        grid(int x, int y, int mine);
        void decrement_safe();
        int get_safe();
        void print_grid();
        void reveal(int x, int y);
        void update_land(int x, int y);
        void flag(int x, int y);
        int peek(int x, int y);
    private:
        grid(); //no default constructor
        land **map;
        int x_size;
        int y_size;
        int safe;
};

grid::grid(int y, int x, int mine)
{
    //this is backwards 'coz i'm a dumbass and programmed it wrong
    x_size = x;
    y_size = y;
    safe = (x * y) - mine; //how many spaces remain

    map = new land*[x_size];
    for(int i=0; i< x_size; i++){
        map[i] = new land[y_size];
    }

    for(int i=0; i<(x_size); i++){
        for(int j=0; j<(y_size); j++){
            map[i][j] = land();
        }
    }

    std::srand(std::time(0)); //seed rand with time
    int i, j = 0;

    while(mine > 0)
    {
        //randomly distribute mines until there are none left
        i = std::rand() % x_size;
        j = std::rand() % y_size;

        if(map[i][j].is_mine() == false)
        {
            map[i][j].set_mine(true);
            mine--;
        }
    }
}

void grid::decrement_safe()
{
    safe--;
}

int grid::get_safe()
{
    return this->safe;
}

//print the entire grid
void grid::print_grid()
{
    //TODO: clean this monster up
    int x_s = this->x_size;
    int y_s = this->y_size;

    int temp;

    std::cout << "\n+  ";
    for(int i=0; i<y_size; i++)
    {
        std::cout << " " << i;
        if(i < 10)
        {
            std::cout << " ";
        }
    }
    std::cout << "\n\n";

    for(int i=0; i<x_s; i++){
        std::cout << i << " ";
        if(i < 10)
        {
            std::cout << " ";
        }

        for(int j=0; j<y_s; j++){

            if(map[i][j].is_visible())
            {
                temp = map[i][j].get_deadly();

                if(map[i][j].is_mine())
                {
                    std::cout << " X ";
                }
                else if(map[i][j].is_flagged())
                {
                    std::cout << "[F]";
                }
                else if(temp != 0)
                {
                    std::cout << " " << temp << " ";
                }
                else
                {
                    std::cout << "   ";
                }
            }
            else
            {
                std::cout << "[ ]";
            }
        }
        std::cout << "\n";
    }

    std::cout << "\n";


    return;
}

//take an x coord and a y coord and reveal that spot
void grid::reveal(int x, int y)
{
    if(map[x][y].is_mine())
    {
        //they picked a mine.

        std::cout << "\nboom.\n";
        //TODO: reveal mines
        map[x][y].set_visible(true);
        print_grid();
        exit(0);
    }
    else if(map[x][y].is_flagged())
    {
        //flagged spaces can't be revealed.
        return;
    }
    else if(map[x][y].is_visible())
    {
        //already revealed
        return;
    }
    else
    {
        update_land(x, y);

        if(map[x][y].get_deadly() == 0)
        {
            //no adjacent mines
            //cascade reveal
            for(int i=(x-1); i<=(x+1); i++)
            {
                if(i >= 0 && i < x_size)
                {
                    for(int j=(y-1); j<=(y+1); j++)
                    {
                        if(j >= 0 && j<y_size)
                        {
                            if(map[i][j].is_visible() == false)
                            //if it's not showing yet
                            reveal(i, j);
                        }
                    }
                }
            }
        }
    }
}

void grid::update_land(int x, int y)
{
    map[x][y].set_deadly(peek(x, y));
    map[x][y].set_visible(true);
    decrement_safe();
}

void grid::flag(int x, int y)
{
    //flip the flag
    map[x][y].set_flagged(!map[x][y].is_flagged());
}

//peek to see how many mines are nearby
int grid::peek(int x, int y)
{
    int count = 0;

    for(int i=(x-1); i<=(x+1); i++)
    {
        if(i >= 0 && i < x_size)
        {
            for(int j=(y-1); j<=(y+1); j++)
            {
                if(j >= 0 && j<y_size)
                {
                    if(map[i][j].is_mine())
                    {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}
