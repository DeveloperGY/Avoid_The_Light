#include <termDisplay.h>
#include "atl_types.hpp"
#include "gameInc.hpp"

#include <iostream>

int main(void)
{
    const int width = 120;
    const int height = 30;

    td_initialize(width, height);

    GameObject *tilemap = new TileMap();
    GameObject *player = new Player(5, 16);






    bool running = true;
    while (running)
    {
        // update
        tilemap->update();
        player->update();

        //draw
        tilemap->draw();


        
        player->draw();
        td_display();
    }

    delete tilemap;

    td_terminate();

    std::cout << "\x1b[0;0H\x1b[0J" << std::endl;

    return 0;
}