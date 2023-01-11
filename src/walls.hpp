#pragma once

#include <termDisplay.h>
#include "atl_types.hpp"
#include "gameObject.hpp"

#include <iostream>
#include <array>

class Walls: public GameObject
{
    private:
        std::array<std::array<int, 120>, 30> arr;

    public:
        Walls();

        void update();
        void draw();

        bool isWall(Vector2i coords);
};