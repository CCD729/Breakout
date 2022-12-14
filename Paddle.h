#ifndef PADDLE_H
#define PADDLE_H

#include "GameObject.h"

namespace gm {
    class Paddle :
        public GameObject
    {
    protected:
        sf::RectangleShape body;
    public:
        Paddle(const sf::Vector2f& position, const sf::Vector2f& size);

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
