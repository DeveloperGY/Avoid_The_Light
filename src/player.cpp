#include "player.hpp"

Player::Player(int x, int y):
	position{Vector2i(x, y)}
{

}

void Player::update()
{

}

void Player::draw()
{
	td_drawPoint(this->position.x, this->position.y, '@', TD_COLOR_BLUE, TD_COLOR_DEFAULT);
}

void Player::move(int x, int y)
{
	this->position.x += x;
	this->position.y += y;
}

Vector2i Player::pos()
{
	return this->position;
}