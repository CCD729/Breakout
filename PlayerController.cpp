#include "PlayerController.h"
#include <iostream>

using namespace sf;
using namespace gm;

PlayerController::PlayerController()  {
}

// Handle ball launch
void PlayerController::handleInput(Event& event, RenderWindow& window, Paddle& paddle, SquareBall& ball, int GameWidth, int GameHeight, bool& isBallLaunched) {
	if (!isBallLaunched && event.type == Event::MouseButtonPressed) {
		if (event.mouseButton.button == Mouse::Left) {
			isBallLaunched = true;
			float currentSpeed = sqrtf(ball.getBaseSpeed() * ball.getBaseSpeed() + ball.getBaseSpeed() * ball.getBaseSpeed()) * ball.getSpeedMultiplier();
			ball.setVelocity(Vector2f((-1) * currentSpeed * sin(45 * 3.14159f / 180), currentSpeed * cos(45 * 3.14159f / 180)));
		}
	}
}

// Handle paddle movement
void PlayerController::handleInput(RenderWindow& window,  Paddle& paddle, SquareBall& ball, int GameWidth, int GameHeight, bool& isBallLaunched) {
	// Paddle movement (within screen)
	if (Mouse::getPosition(window).x < paddle.getSize().x / 2) {
		paddle.setPosition(Vector2f(0, paddle.getPosition().y));
	}
	else if (Mouse::getPosition(window).x > GameWidth - paddle.getSize().x / 2) {
		paddle.setPosition(Vector2f(GameWidth - paddle.getSize().x, paddle.getPosition().y));
	}
	else
		paddle.setPosition(Vector2f(Mouse::getPosition(window).x - paddle.getSize().x / 2, paddle.getPosition().y));
	// Ball sticks to paddle if not launched
	if (!isBallLaunched) {
		ball.setPosition(paddle.getPosition() - Vector2f(-30, ball.getSize().y - 2.f));
	}
}

void PlayerController::update(Paddle& paddle, int GameWidth) {

}
PlayerController::~PlayerController() {

}