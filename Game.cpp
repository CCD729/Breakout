// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"
#include <iostream>

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;

// Repeated Levels
int level1grid[9][10] = {
	{2,1,1,1,1,1,1,1,1,2},
	{1,2,1,2,2,2,2,1,2,1},
	{1,1,2,0,0,0,0,2,1,1},
	{1,1,1,2,0,0,2,1,1,1},
	{0,0,0,0,0,0,0,0,0,0},
	{1,1,1,2,0,0,2,1,1,1},
	{1,0,2,0,0,0,0,2,0,1},
	{2,2,0,0,0,0,0,0,2,2},
	{2,0,0,0,0,0,0,0,0,2}
};
int level2grid[9][10] = {
	{0,1,3,0,0,0,0,3,1,0},
	{0,3,1,3,1,1,3,1,3,0},
	{3,1,2,1,3,3,1,2,1,3},
	{0,0,2,0,0,0,0,2,0,0},
	{1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0},
	{1,2,1,2,1,2,1,2,1,2},
	{2,1,2,1,2,1,2,1,2,1},
	{1,1,1,1,1,1,1,1,1,1}
};
int level3grid[9][10] = {
	{1,1,1,2,2,2,2,1,1,1},
	{2,0,0,0,0,0,0,0,0,0},
	{3,3,3,3,3,3,3,3,3,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,3,3,3,3,3,3,3,3,3},
	{0,0,0,0,0,0,0,0,0,0},
	{3,3,3,3,3,3,3,3,3,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,3,3,3,3,3,3,3,3,3}
};

// Easy Tutorial Levels
int levelb2grid[9][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,1,0,2,2,0,1,0,0},
	{0,0,0,3,1,1,3,0,0,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
};
int levelb1grid[9][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{1,1,0,0,3,3,0,0,1,1},
	{0,1,1,2,0,0,2,1,1,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
};
int level0grid[9][10] = {
	{1,2,2,0,3,3,0,2,2,1},
	{0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
};

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), clock(), deltaTime(0), gameState(GameState::Menu), isBallLaunched(false), paddle(Vector2f(GameWidth/2-50, GameHeight - 50), Vector2f(100, 15)), ball(Vector2f(GameWidth / 2 - 5, GameHeight / 2 - 5), Vector2f(10, 10), 200), level1(level1grid, float(GameWidth), float(GameHeight/64*27), 9, 10), level2(level2grid, float(GameWidth), float(GameHeight / 64 * 27), 9, 10), level3(level3grid, float(GameWidth), float(GameHeight / 64 * 27), 9, 10), levelCounter(0), currentSpeedMultiplier(1.f), levelb2(levelb2grid, float(GameWidth), float(GameHeight / 64 * 27), 9, 10), levelb1(levelb1grid, float(GameWidth), float(GameHeight / 64 * 27), 9, 10), level0(level0grid, float(GameWidth), float(GameHeight / 64 * 27), 9, 10) {
	// Set our fps to 60
	window.setFramerateLimit(60);
	// Hide mouse cursor
	window.setMouseCursorVisible(false);
}

void Game::run() {
	// This is our game loop!
	//ball.setVelocity(Vector2f(ball.getBaseSpeed(), ball.getBaseSpeed()));
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
		// Handle Input for each state
		if (gameState == GameState::Menu) { // Simply change state
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					GameStateChange(GameState::InGame);
				}
			}
		}
		else if (gameState == GameState::InGame) {
			playerController.handleInput(event, window, paddle, ball, GameWidth, GameHeight, isBallLaunched);
		}
		else if (gameState == GameState::EndGame) { // Simply change state
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Right) {
					GameStateChange(GameState::Menu);
				}
			}
		}

	}
	// Outside events because we want to handle out-of-window movements
	if (gameState == GameState::InGame) {
		playerController.handleInput(window, paddle, ball, GameWidth, GameHeight, isBallLaunched);
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	// Game update
	if (gameState == GameState::InGame) {
		// Game logic update
		paddle.update(window, deltaTime);
		ball.update(window, deltaTime);

		// Collision handling with paddles
		if (isBallLaunched) {
			if (ball.collide(paddle.getCollider()) || // edge case: ball in the paddle due to speed
				(ball.getCollider().left > paddle.getCollider().left && ball.getCollider().left + ball.getSize().x < paddle.getCollider().left + paddle.getSize().x &&
					ball.getCollider().top >paddle.getCollider().top && ball.getCollider().top + ball.getSize().y < paddle.getCollider().top + paddle.getSize().y)) {
				//SFX
				//soundManager.PlaySFX(SFX::bounce);
				ball.Bounce(paddle);
			}
			// If hitting up or down edge
			else if (ball.getPosition().y < 30 || ball.getPosition().x < 0 || ball.getPosition().x > GameWidth - ball.getSize().x) {
				//SFX
				//soundManager.PlaySFX(SFX::bounce);
				ball.Bounce(GameHeight, GameWidth);
			} // If fail to catch the ball
			else if (ball.getPosition().y > GameHeight) {
				//SFX
				//soundManager.PlaySFX(SFX::dead);

				// Stop the ball and stick it to paddle
				isBallLaunched = false;
				ball.setPosition(paddle.getPosition() - Vector2f(-20, ball.getSize().y + 2.f));
				ball.setVelocity(Vector2f(0, 0));
				// Trigger respawn 
				if (ui.GetLives() > 1) {
					//std::cout << ui.GetLives() << isBallLaunched << std::endl;
					ui.SetLives(ui.GetLives() - 1);
					ball.setSpeedMultiplier(currentSpeedMultiplier);
				}
				else { // Game over
					ui.SetLives(ui.GetLives() - 1);
					GameStateChange(GameState::EndGame);
				}
			}
			// Brick collision
			for (int i = 0; i < int(currentLevel->getBricks().size());) {
				Brick* brick = currentLevel->getBricks()[i].get();
				if (ball.collide(brick->getCollider())) {
					ball.Bounce(*brick);
					brick->hit();
					if (brick->isDead()) {
						ui.SetScore(ui.GetScore() + brick->getPoint());
						currentLevel->getBricks().erase(currentLevel->getBricks().begin() + i);
						continue;
					}
				}
				i++;
			}
		}
		// Level update
		currentLevel->update(window, deltaTime);

		// Winning check / respawn ball [TODO]
		if (currentLevel->getBricks().empty()) {
			// Load next level
			levelCounter++;
			Game::loadLevel(levelCounter);
			if (levelCounter <= 0) {
				if (levelCounter == 0)
					ui.SetLevel(3);
				else if (levelCounter == -1)
					ui.SetLevel(2);
				else
					ui.SetLevel(1);
			}
			else {
				ui.SetLevel(levelCounter+3);
			}
			// Reset the ball
			ball.setVelocity(Vector2f(0, 0));
			isBallLaunched = false;
			if (currentSpeedMultiplier < ball.getMaxSpeedMultiplier())
				currentSpeedMultiplier += 0.1f;
			else
				currentSpeedMultiplier = ball.getMaxSpeedMultiplier();
			ball.setSpeedMultiplier(currentSpeedMultiplier);
		}
	}
	// Score UI update
	ui.update(window, gameState);
	std::cout << "ballSpeed: " <<ball.getSpeedMultiplier()<<", " <<sqrtf(ball.getVelocity().x*ball.getVelocity().x+ ball.getVelocity().y* ball.getVelocity().y) << " level multiplier: " << currentSpeedMultiplier << std::endl;
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	// Game objects render
	if (gameState == GameState::InGame) {
		paddle.render(window,deltaTime);
		ball.render(window,deltaTime);
		// Level render
		currentLevel->render(window, deltaTime);
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
		// Level size(temp 9 * 10 270 * 640)
		// Initalize (based on game mode)
		// First recenter the ball and paddle
		//ball.setPosition(centerPosition - Vector2f(ball.getSize().x / 2, ball.getSize().y / 2));
		//paddle.setPosition(paddle1Position - Vector2f(paddle.getSize().x / 2, paddle.getSize().y / 2));

		//lives = 3;
		levelCounter = -2;
		Game::loadLevel(levelCounter);
		ui.SetScore(0);
		ui.SetLevel(1);
		ui.SetLives(3);
		currentSpeedMultiplier = 1.f;
		ball.setSpeedMultiplier(currentSpeedMultiplier);
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

void Game::loadLevel(int level) {
	if (level <= 0) {
		switch (level) {
		case -2:
			currentLevel = &levelb2;
			break;
		case -1:
			currentLevel = &levelb1;
			break;
		case 0:
			currentLevel = &level0;
			break;
		}
	}
	else {
		switch (level % 3) {
		case 1:
			currentLevel = &level1;
			break;
		case 2:
			currentLevel = &level2;
			break;
		case 0:
			currentLevel = &level3;
			break;
		}
	}
	currentLevel->reset();
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