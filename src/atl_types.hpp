#pragma once

enum Direction
{
    North,
    South,
    East,
    West
};

class Vector2i
{
    private:

    public:
        int x;
        int y;
        
        Vector2i(int x, int y);
};