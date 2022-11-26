#include "PlayerController.h"

using namespace sf;
using namespace gm;

PlayerController::PlayerController()  {
}
void PlayerController::handleInput(RenderWindow& window,  Paddle& paddle, int GameWidth, int GameHeight) {
	// Paddle movement (within screen)
	if (Mouse::getPosition(window).x < paddle.getSize().x / 2) {
		paddle.setPosition(Vector2f(0, paddle.getPosition().y));
	}
	else if (Mouse::getPosition(window).x > GameWidth - paddle.getSize().x / 2) {
		paddle.setPosition(Vector2f(GameWidth - paddle.getSize().x, paddle.getPosition().y));
	}
	else
		paddle.setPosition(Vector2f(Mouse::getPosition(window).x - paddle.getSize().x / 2, paddle.getPosition().y));
}
void PlayerController::update(Paddle& paddle, int GameWidth) {

}
PlayerController::~PlayerController() {

}