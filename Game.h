// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef GAME_H
#define GAME_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

 /* Our Includes */
#include "GameObject.h"
#include "UI.h"
#include "Paddle.h"
#include "SquareBall.h"
#include "PlayerController.h"
#include "Level.h"

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {

	const int GameWidth = 640;
	const int GameHeight = 640;

	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	private:
		// The game window
		sf::RenderWindow window;
		// For tracking/maintaining delta time
		sf::Clock clock;
		float deltaTime;
		// UI elements
		UI ui;
		// Current game state
		GameState gameState;
		// Player controller
		PlayerController playerController;
		// Game objects
		Level* currentLevel;
		Level level1, level2, level3;
		SquareBall ball;
		Paddle paddle;
		// Game state variables
		bool isBallLaunched;
		
		// PlayerController
		//PlayerController playerController;
		//SoundManager
		//SoundManager soundManager;
	public:
		/* Protoypes */
		// Constructor
		Game();
		// Will start and manage the game loop programming pattern
		void run();
		// Game Loop Programming Pattern Methods
		void handleInput();
		void update();
		void render();
		// State Manager
		void GameStateChange(GameState state);
		// Level loader
		void loadLevel(int level);
		// Destructor
		~Game();
	};
	//Help functions
	int Rand(int min, int max);
	float Randf(float min, float max);
}

#endif