// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), clock(), deltaTime(0), gameState(GameState::EndGame) {
	// Set our fps to 60
	window.setFramerateLimit(60);
}

void Game::run() {
	// This is our game loop!
	// All input, logic, and rendering should be handled here
	while (window.isOpen())
	{
		// Every frame we...
		// Keep track of the delta time for smoother movement
		deltaTime = clock.restart().asSeconds();

		// Handle input first...
		handleInput();

		// Then update...
		update();

		// Then render...
		render();
	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() {
	// Check for events from the window
	// E.g., is the window being closed?
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
		if (gameState == GameState::Menu) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					GameStateChange(GameState::InGame);
				}
			}
		}
		else if (gameState == GameState::InGame) {
			//playerController.handleInput(event, paddle, GameWidth);
		}
		else if (gameState == GameState::EndGame) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Right) {
					GameStateChange(GameState::Menu);
				}
			}
		}

		// handle some key 
		/*if (event.type == Event::KeyPressed) {

		}*/

	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	// Game update
	if (gameState == GameState::InGame) {
		// Game logic update
	}
	// Score UI update
	ui.update(window, gameState);

}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	// Game objects render
	if (gameState == GameState::InGame) {
		//window.draw(paddle);
		//window.draw(ball);
		//TODO: Draw bricks in level (object list)
	}

	// UI element render
	ui.render(window, gameState);

	// Display the window buffer for this frame
	window.display();
}

//Switch game state functions
void Game::GameStateChange(GameState state) {
	if (state == GameState::Menu) {
		gameState = GameState::Menu;
	}
	else if (state == GameState::InGame) {
		gameState = GameState::InGame;
		// Reset (from menu or end, gamemode keeps)

		// Initalize (based on game mode)
		// First recenter the ball and paddle
		//ball.setPosition(centerPosition - Vector2f(ball.getSize().x / 2, ball.getSize().y / 2));
		//paddle.setPosition(paddle1Position - Vector2f(paddle.getSize().x / 2, paddle.getSize().y / 2));

		//lives = 3;
		//level.SetLevel(1);
		ui.SetScore(0);
		ui.SetLevel(1);
		ui.SetLives(3);
	}
	else if (state == GameState::EndGame) {
		gameState = GameState::EndGame;
		// Retrieve score
		//ui.SetScore(score);
		// Reset
		// Stop and reposition the ball and paddle
		//ball.setPosition(centerPosition - Vector2f(ball.getSize().x / 2, ball.getSize().y / 2);
		//ball.setVelocity(Vector2f(0, 0));
		//paddle.setPosition(paddlePosition - Vector2f(paddle.getSize().x / 2, paddle.getSize().y / 2));
		
		// Clear current level bricks object list
		// 
	}
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {
	//bricks free should be handled when level changes
}

//Help functions
//Randoms
int gm::Rand(int min, int max) // Ranged
{
	static bool setup = true;
	if (setup)
	{
		srand(unsigned int(time(NULL))); //seeding
		setup = false;
	}
	int tmp = min + rand() % ((max + 1) - min);
	return (tmp == 0) ? 1 : tmp;
}

float gm::Randf(float min, float max) {
	static bool setup = true;
	if (setup)
	{
		srand(unsigned int(time(NULL))); //seeding
		setup = false;
	}
	return (min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min))));
}