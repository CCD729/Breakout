#include "UI.h"
#include <iostream>

using namespace gm;
using namespace sf;

UI::UI() : score(0), level(1), lives(3) {
	// UI content setup
	// Initial Setup for menu UI
	if (!font.loadFromFile("Assets/PressStart2P-vaV7.ttf"))
	{
		// error...
		std::cerr << "Error: Failed to load font!" << std::endl;
		exit(-1);
	}
	// select the font
	titleText.setFont(font);
	introText.setFont(font);
	beginPromptText.setFont(font);
	scoreText.setFont(font);
	levelText.setFont(font);
	livesText.setFont(font);
	gameOverText.setFont(font);
	endScoreText.setFont(font);
	restartPromptText.setFont(font);
	// set the string to display
	titleText.setString("BREAKOUT");
	introText.setString("Break the bricks!");
	beginPromptText.setString("Mouse left click to start");
	scoreText.setString("Score: 0");
	levelText.setString("Level 1");
	livesText.setString("Lives: 3");
	gameOverText.setString("GAME OVER");
	endScoreText.setString("Your score: 0");
	restartPromptText.setString("Mouse right click to menu");
	// set the character size (in pixels)
	titleText.setCharacterSize(48);
	introText.setCharacterSize(24);
	beginPromptText.setCharacterSize(22);
	scoreText.setCharacterSize(18);
	levelText.setCharacterSize(18);
	livesText.setCharacterSize(18);
	gameOverText.setCharacterSize(36);
	endScoreText.setCharacterSize(24);
	restartPromptText.setCharacterSize(22);
	// set the color
	titleText.setFillColor(sf::Color::White);
	introText.setFillColor(sf::Color::White);
	beginPromptText.setFillColor(sf::Color::White);
	scoreText.setFillColor(sf::Color::White);
	levelText.setFillColor(sf::Color::White);
	livesText.setFillColor(sf::Color::White);
	gameOverText.setFillColor(sf::Color::White);
	endScoreText.setFillColor(sf::Color::White);
	restartPromptText.setFillColor(sf::Color::White);
	// set the text style
	titleText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	introText.setStyle(sf::Text::Regular);
	beginPromptText.setStyle(sf::Text::Bold);
	scoreText.setStyle(sf::Text::Regular);
	levelText.setStyle(sf::Text::Regular);
	livesText.setStyle(sf::Text::Regular);
	gameOverText.setStyle(sf::Text::Bold);
	endScoreText.setStyle(sf::Text::Regular);
	restartPromptText.setStyle(sf::Text::Regular);
	// set the position
	titleText.setPosition(Vector2f(130, 90));
	introText.setPosition(Vector2f(130, 265));
	beginPromptText.setPosition(Vector2f(35, 420));
	scoreText.setPosition(Vector2f(230, 10));
	levelText.setPosition(Vector2f(10, 10));
	livesText.setPosition(Vector2f(485, 10));
	gameOverText.setPosition(Vector2f(155, 100));
	endScoreText.setPosition(Vector2f(130, 265));
	restartPromptText.setPosition(Vector2f(50, 420));
}
int UI::GetScore() const {
	return score;
}

void UI::SetScore(int score) {
	this->score = score;
	scoreText.setString("Score: "+std::to_string(score));
	endScoreText.setString("Your score: " + std::to_string(score));
}

int UI::GetLevel() const {
	return level;
}

void UI::SetLevel(int level) {
	this->level = level;
	levelText.setString("Level " + std::to_string(level));
}

int UI::GetLives() const {
	return lives;
}

void UI::SetLives(int lives) {
	this->lives = lives;
	livesText.setString("Lives: " + std::to_string(lives));
}

void UI::update(RenderWindow& window, GameState gamestate) {
	if (gamestate == GameState::Menu) {
		//Nothing
	}
	else if (gamestate == GameState::InGame) {
		//Update score... maybe in game update using SetScore()...
	}
	else if (gamestate == GameState::EndGame) {
		//Nothing
	}
}
void UI::render(RenderWindow& window, GameState gamestate) {
	if (gamestate == GameState::Menu) {
		window.draw(titleText);
		window.draw(introText);
		window.draw(beginPromptText);
	}
	else if (gamestate == GameState::InGame) {
		window.draw(scoreText);
		window.draw(levelText);
		window.draw(livesText);
	}
	else if (gamestate == GameState::EndGame) {
		window.draw(gameOverText);
		window.draw(endScoreText);
		window.draw(restartPromptText);
	}
}
UI::~UI() {

}