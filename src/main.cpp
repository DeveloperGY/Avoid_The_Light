#include <termDisplay.h>
#include "atl_types.hpp"
#include "gameObj.hpp"

int main(void)
{
    const int width = 120;
    const int height = 30;

    td_initialize(width, height);

    GameObject *walls = new Walls();






    bool running = true;
    while (running)
    {
        // update
        walls->update();

        //draw
        walls->draw();
        td_drawPoint(5, 15, '@', TD_COLOR_BLUE, TD_COLOR_DEFAULT);
        td_display();
    }

    delete walls;

    td_terminate();

    return 0;
}