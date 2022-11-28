#include "Brick.h"

using namespace sf;
using namespace gm;

Brick::Brick(const Vector2f& position, const Vector2f& size, BrickType* t) : GameObject(position, size) {
	body.setPosition(position);
	body.setSize(size);
	type = t;
	hp = t->hp;
	pointworth = t->pointworth;
	body.setFillColor(t->color);
}

void Brick::update(sf::RenderWindow& window, float deltaTime) {

}

void Brick::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

void Brick::setPosition(const Vector2f& position) {
	GameObject::setPosition(position);
	// Don't forget to update the Box's shape position to match the new position
	body.setPosition(position);
}

const Color& Brick::getFillColor() const {
	return body.getFillColor();
}

void Brick::setFillColor(const Color& color) {
	body.setFillColor(color);
}

const Vector2f Brick::getSize() const {
	return body.getSize();
}

void Brick::setSize(const Vector2f& size) {
	body.setSize(size);
}

int Brick::getPoint() const {
	return pointworth;
}

// Hit lose HP
void Brick::hit() {
	hp--;
	if (hp == 2) {
		body.setFillColor(Color::Cyan);
	}
	else if (hp == 1) {
		body.setFillColor(Color::White);
	}
}
// isDead
bool Brick::isDead() const {
	return hp == 0;
}