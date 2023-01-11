#include <termDisplay.h>
#include "atl_types.hpp"
#include "gameInc.hpp"

#include <iostream>
#include <chrono>
#include <string>

int main(void)
{
    const int width = 120;
    const int height = 30;

    td_initialize(width, height);

    TileMap *tilemap = new TileMap();
    Player *player = new Player(100, 10);




    bool running = true;

    auto current_time = std::chrono::system_clock::now();
    auto previous_time = current_time;
    float dt = 0.0f;
    float total_time = 0;
    float max_time = 300000;
    std::string time_str = "";

    while (running)
    {
        // handle time
        current_time = std::chrono::system_clock::now();

        dt = std::chrono::duration_cast<std::chrono::milliseconds>((current_time-previous_time)).count();
        total_time += (dt/1000);

        int minute = (int)((int)(max_time-total_time) / 60000);
        int second = (int)((int)(max_time-total_time) % 60);
        time_str.append(std::to_string(minute));
        time_str.append(":");
        time_str.append(std::to_string(second));

        // input
        switch (getch(0))
        {
            case NULL:
            {
                break;
            }

            case 'w':
            {
                Vector2i plr_pos = player->pos();
                --plr_pos.y;
                if (tilemap->isWall(plr_pos))
                {
                    break;
                }
                player->move(0, -1);
                break;
            }
            
            case 'a':
            {
                Vector2i plr_pos = player->pos();
                --plr_pos.x;
                if (tilemap->isWall(plr_pos))
                {
                    break;
                }
                player->move(-1, 0);
                break;
            }

            case 's':
            {
                Vector2i plr_pos = player->pos();
                ++plr_pos.y;
                if (tilemap->isWall(plr_pos))
                {
                    break;
                }
                player->move(0, 1);
                break;
            }

            case 'd':
            {
                Vector2i plr_pos = player->pos();
                ++plr_pos.x;
                if (tilemap->isWall(plr_pos))
                {
                    break;
                }
                player->move(1, 0);
                break;
            }

            case 'q':
            {
                running = false;
                break;
            }
        }

        // update
        tilemap->update();
        player->update();

        //draw
        tilemap->draw();
        td_drawTextHorizontal(0, 0, time_str.c_str(), TD_COLOR_BLACK, TD_COLOR_WHITE);

        td_drawLine(1, 28, 118, 1, '#', TD_COLOR_RED, TD_COLOR_RED);        
        
        player->draw();
        td_display();

        time_str = "";
        previous_time = current_time;
    }

    delete tilemap;
    delete player;

    td_terminate();

    return 0;
}