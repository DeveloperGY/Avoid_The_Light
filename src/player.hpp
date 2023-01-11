#pragma once

#include <termDisplay.h>
#include "atl_types.hpp"
#include "gameObject.hpp"

class Player: public GameObject
{
	private:
		Vector2i pos;

	public:
		Player(int x, int y);

		void update();
		void draw();
};