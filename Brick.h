#ifndef BRICK_H
#define BRICK_H

#include "GameObject.h"

namespace gm {
	// Brick types
	struct BrickType {
		int hp;
		sf::Color color;
		int pointworth;
	};
	BrickType normal_brick = {
		1,
		sf::Color::White,
		50
	};
	BrickType hard_brick = {
		2,
		sf::Color::Cyan,
		125
	};
	BrickType tough_brick = {
		3,
		sf::Color::Blue,
		200
	};

	class Brick :
		public GameObject
	{
	protected:
		int hp;
		int pointworth;
		sf::RectangleShape body;
		const BrickType* type;
	public:
		Brick(const sf::Vector2f& position, const sf::Vector2f& size, BrickType* t);

		virtual void update(sf::RenderWindow& window, float deltaTime) override;

		virtual void render(sf::RenderWindow& window, float deltaTime) override;

		virtual void setPosition(const sf::Vector2f& position) override;

		// Move from current position to a new one with a specified velocity
		// Maybe when tweening kicks in (stretch goal)
		//virtual void move(const sf::Vector2f& velocity) override;

		const sf::Color& getFillColor() const;

		void setFillColor(const sf::Color& color);

		const sf::Vector2f getSize() const;

		void setSize(const sf::Vector2f& size);

	};
}

#endif