#include "SquareBall.h"
#include <iostream>

using namespace sf;
using namespace gm;

SquareBall::SquareBall(const Vector2f& position, const Vector2f& size, float baseSpeed) : GameObject(position, size), baseSpeed(baseSpeed), speedMultiplier(1) {
	body.setPosition(position);
	body.setSize(size);
	velocity = Vector2f(0, 0);
}

void SquareBall::update(sf::RenderWindow& window, float deltaTime){
	//move(Vector2f(PlayerMovementSpeedPerSecond * direction * deltaTime, 0));
	move(Vector2f(velocity.x * deltaTime * speedMultiplier , velocity.y * deltaTime * speedMultiplier));
}

void SquareBall::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

void SquareBall::setPosition(const Vector2f& position) {
	GameObject::setPosition(position);
	// Don't forget to update the Box's shape position to match the new position
	body.setPosition(position);
}

void SquareBall::move(const Vector2f& velocity) {
	GameObject::move(velocity);
	// Don't forget to update the Box's shape position to match the new position
	body.setPosition(position);
}

const Color& SquareBall::getFillColor() const {
	return body.getFillColor();
}

void SquareBall::setFillColor(const Color& color) {
	body.setFillColor(color);
}

const Vector2f& SquareBall::getVelocity() const {
	return velocity;
}

void SquareBall::setVelocity(const Vector2f& velocity) {
	this->velocity = velocity;
}

const Vector2f SquareBall::getSize() const {
	return body.getSize();
}

void SquareBall::setSize(const Vector2f& size) {
	body.setSize(size);
}

float SquareBall::getBaseSpeed() const {
	return baseSpeed;
}

void SquareBall::setBaseSpeed(float speed) {
	baseSpeed = speed;
}

// Bounce off paddle
void SquareBall::Bounce(const Paddle& paddle) {
	// Determine collision from which direction
	float b_collision = paddle.getCollider().top + paddle.getCollider().height - collider.top;
	float t_collision = collider.top+collider.height - paddle.getCollider().top;
	float l_collision = collider.left + collider.width - paddle.getCollider().left;
	float r_collision = paddle.getCollider().left + paddle.getCollider().width - collider.left;

	if (t_collision < b_collision && t_collision < l_collision && t_collision < r_collision) {
		float currentSpeed = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y) * speedMultiplier;
		// Collision from top (increase speed)
		// Different angle for x
		if (getPosition().x + getSize().x / 2 < paddle.getPosition().x + paddle.getSize().x / 6) {
			//left most angle
			velocity.x = (-1) * currentSpeed * sin(60 * 3.14159f / 180);
			velocity.y = currentSpeed * cos(60 * 3.14159f / 180);
		}
		else if (getPosition().x + getSize().x / 2 < paddle.getPosition().x + paddle.getSize().x / 3) {
			//second left angle
			velocity.x = (-1) * currentSpeed * sin(45 * 3.14159f / 180);
			velocity.y = currentSpeed * cos(45 * 3.14159f / 180);
		}
		else if (getPosition().x + getSize().x / 2 < paddle.getPosition().x + paddle.getSize().x / 2) {
			//third left angle
			velocity.x = (-1) * currentSpeed * sin(30 * 3.14159f / 180);
			velocity.y = currentSpeed * cos(30 * 3.14159f / 180);
		}
		else if (getPosition().x + getSize().x / 2 < paddle.getPosition().x + paddle.getSize().x / 3 * 2) {
			//third right angle
			velocity.x = currentSpeed * sin(30 * 3.14159f / 180);
			velocity.y = currentSpeed * cos(30 * 3.14159f / 180);
		}
		else if (getPosition().x + getSize().x / 2 < paddle.getPosition().x + paddle.getSize().x / 6 * 5) {
			//second right angle
			velocity.x = currentSpeed * sin(45 * 3.14159f / 180);
			velocity.y = currentSpeed * cos(45 * 3.14159f / 180);
		}
		else {
			//most right angle
			velocity.x = currentSpeed * sin(60 * 3.14159f / 180);
			velocity.y = currentSpeed * cos(60 * 3.14159f / 180);
		}
		velocity.y = (-1) * velocity.y;
		speedMultiplier += 0.005f;

		// Reset position
		setPosition(Vector2f(getPosition().x, paddle.getPosition().y-getSize().y-0.1f));
	}
	else if (b_collision < t_collision && b_collision < l_collision && b_collision < r_collision)
	{
		// Collision from bottom (not possible)
	}
	else if (l_collision < r_collision && l_collision < t_collision && l_collision < b_collision)
	{
		// Collision from left
		velocity.x = (-1) * velocity.x;
		// Reset position
		setPosition(Vector2f(paddle.getPosition().x-getSize().x-0.1f, getPosition().y));
	}
	else if (r_collision < l_collision && r_collision < t_collision && r_collision < b_collision)
	{
		// Collision from right
		velocity.x = (-1) * velocity.x;
		// Reset position
		setPosition(Vector2f(paddle.getPosition().x + paddle.getSize().x + 0.1f, getPosition().y));
	}
	// Emergency fast collision workaround
	else if (getPosition().y > paddle.getPosition().y && getPosition().x > paddle.getPosition().x && getPosition().x + getSize().x < paddle.getPosition().x + paddle.getSize().x) {
		float currentSpeed = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y) * speedMultiplier;
		// Collision from top (increase speed)
		// Different angle for x
		if (getPosition().x + getSize().x / 2 < paddle.getPosition().x + paddle.getSize().x / 6) {
			//left most angle
			velocity.x = (-1) * currentSpeed * sin(60 * 3.14159f / 180);
			velocity.y = currentSpeed * cos(60 * 3.14159f / 180);
		}
		else if (getPosition().x + getSize().x / 2 < paddle.getPosition().x + paddle.getSize().x / 3) {
			//second left angle
			velocity.x = (-1) * currentSpeed * sin(45 * 3.14159f / 180);
			velocity.y = currentSpeed * cos(45 * 3.14159f / 180);
		}
		else if (getPosition().x + getSize().x / 2 < paddle.getPosition().x + paddle.getSize().x / 2) {
			//third left angle
			velocity.x = (-1) * currentSpeed * sin(30 * 3.14159f / 180);
			velocity.y = currentSpeed * cos(30 * 3.14159f / 180);
		}
		else if (getPosition().x + getSize().x / 2 < paddle.getPosition().x + paddle.getSize().x / 3 * 2) {
			//third right angle
			velocity.x = currentSpeed * sin(30 * 3.14159f / 180);
			velocity.y = currentSpeed * cos(30 * 3.14159f / 180);
		}
		else if (getPosition().x + getSize().x / 2 < paddle.getPosition().x + paddle.getSize().x / 6 * 5) {
			//second right angle
			velocity.x = currentSpeed * sin(45 * 3.14159f / 180);
			velocity.y = currentSpeed * cos(45 * 3.14159f / 180);
		}
		else {
			//most right angle
			velocity.x = currentSpeed * sin(60 * 3.14159f / 180);
			velocity.y = currentSpeed * cos(60 * 3.14159f / 180);
		}
		velocity.y = (-1) * velocity.y;
		speedMultiplier += 0.005f;

		// Reset position
		setPosition(Vector2f(getPosition().x, paddle.getPosition().y - getSize().y - 0.1f));
	}
}

// Bounce off brick
/*void SquareBall::Bounce(const Brick& brick) {

}*/

// overloaded Bounce when it reaches the top/bottom of screen
void SquareBall::Bounce(int GameHeight, int GameWidth) {
	// If top or bottom
	if (getPosition().y < 0) {
		velocity.y = (-1) * velocity.y;
	}
	// If side
	if (getPosition().x < 0 || getPosition().x > GameWidth-getSize().x) {
		velocity.x = (-1) * velocity.x;
	}
	// Reset position to avoid weird things
	if (getPosition().y < 0) {
		setPosition(Vector2f(getPosition().x, 0.1f));
	}
	if (getPosition().x < 0) {
		setPosition(Vector2f(0.1f, getPosition().y));
	}
	else if (getPosition().x > GameWidth - getSize().x) {
		setPosition(Vector2f(GameWidth - getSize().x - 0.1f, getPosition().y));
	}
}