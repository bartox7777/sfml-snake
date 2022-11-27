#pragma once
#include "Square.h"

class Block : public Square{
    public:
        enum direction{
            NONE,
            UP,
            DOWN,
            LEFT,
            RIGHT
        };

        Block(sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color::Red, direction blockDirection = direction::NONE);

        void draw(sf::RenderTarget& target) const;

        sf::Vector2f getPosition() const;
        void setPosition(sf::Vector2f position);

        direction getDirection() const;
        void setDirection(direction direction);

    private:
        direction blockDirection;
};
