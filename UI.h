#ifndef UI_H
#define UI_H

#include "GameObject.h"

namespace gm {
	class UI
	{
	protected:
		int score, level, lives;
		sf::Text titleText, introText, beginPromptText, scoreText, levelText, livesText, gameOverText, endScoreText, restartPromptText;
		sf::Font font;
	public:
		UI();
		int GetScore() const;
		void SetScore(int score);
		int GetLevel() const;
		void SetLevel(int level);
		int GetLives() const;
		void SetLives(int lives);
		void update(sf::RenderWindow& window, GameState gamestate);
		void render(sf::RenderWindow& window, GameState gamestate);
		~UI();
	};
}

#endif
