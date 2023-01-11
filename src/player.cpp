#include "player.hpp"

Player::Player(int x, int y):
	pos{Vector2i(x, y)}
{

}

void Player::update()
{

}

void Player::draw()
{
	td_drawPoint(this->pos.x, this->pos.y, '@', TD_COLOR_BLUE, TD_COLOR_DEFAULT);
}