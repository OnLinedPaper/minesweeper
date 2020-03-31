class land
{
    public:
        land();
        bool is_mine(void); //is it a mine
        void set_mine(bool val);

        int get_deadly(void); //get the count
        void set_deadly(int count);

        bool is_visible(void); //sees if it's visible
        void set_visible(bool val);

        bool is_flagged(void);
        void set_flagged(bool val);

    private:
        bool visible; //is it visible
        bool mine; //is it a mine
        int deadly; //how many of its neighbors are mines
        bool flagged;
};

land::land(void)
{
    visible = false;
    mine = false;
    deadly = 0;
    flagged = false;
}

bool land::is_mine(void)
{
    return this->mine;
}

void land::set_mine(bool val)
{
    this->mine = val;
}

int land::get_deadly(void)
{
    return this->deadly;
}

void land::set_deadly(int count)
{
    this->deadly = count;
}

bool land::is_visible()
{
    return this->visible;
}

void land::set_visible(bool val)
{
    this->visible = val;
}

bool land::is_flagged()
{
    return this->flagged;
}

void land::set_flagged(bool val)
{
    this->flagged = val;
}



void reveal(land ** grid, int x_size, int y_size, int x_coord, int y_coord)
{
    return;
}
