#ifndef SQUARE_BALL_H
#define SQUARE_BALL_H

#include "GameObject.h"
#include "Paddle.h"

namespace gm {
    class SquareBall :
        public GameObject
    {
    protected:
        sf::RectangleShape body;
        sf::Vector2f velocity;
        float baseSpeed,speedMultiplier;

    public:
        SquareBall(const sf::Vector2f& position, const sf::Vector2f& size, int baseSpeed);

        virtual void update(sf::RenderWindow& window, float deltaTime) override;

        virtual void render(sf::RenderWindow& window, float deltaTime) override;

        virtual void setPosition(const sf::Vector2f& position) override;

        // Move from current position to a new one with a specified velocity
        virtual void move(const sf::Vector2f& velocity) override;

        const sf::Color& getFillColor() const;

        void setFillColor(const sf::Color& color);

        const sf::Vector2f getSize() const;

        void setSize(const sf::Vector2f& size);

        const sf::Vector2f& getVelocity() const;

        void setVelocity(const sf::Vector2f& velocity);

        // Bouncing on paddle
        void Bounce(const Paddle& paddle);

        // Bouncing on brick
        //void Bounce(const Brick& brick);

        // overloaded Bounce when it reaches the edges of screen
        void Bounce(int GameHeight, int GameWidth);
    };
}

#endif