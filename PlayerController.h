#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Paddle.h"

namespace gm {
	class PlayerController
	{
	public:
		PlayerController();
		void handleInput(sf::RenderWindow& window, Paddle& paddle, int GameWidth, int GameHeight);
		void update(Paddle& paddle, int GameWidth);
		~PlayerController();
	};
}
#endif
