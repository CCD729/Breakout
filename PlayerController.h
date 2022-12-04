#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Paddle.h"
#include "SquareBall.h"
#include "SoundManager.h"

namespace gm {
	class PlayerController
	{
	public:
		PlayerController();
		void handleInput(sf::Event& event, sf::RenderWindow& window, Paddle& paddle, SquareBall& ball, int GameWidth, int GameHeight, bool& isBallLaunched, SoundManager& soundManager);
		void handleInput(sf::RenderWindow& window, Paddle& paddle, SquareBall& ball, int GameWidth, int GameHeight, bool& isBallLaunched);
		void update(Paddle& paddle, int GameWidth);
		~PlayerController();
	};
}
#endif
