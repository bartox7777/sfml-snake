#pragma once

#include <SFML/Graphics.hpp>

class Square{
    public:
        virtual void draw(sf::RenderTarget&) const = 0;

        virtual sf::Vector2f getPosition() const = 0;
        virtual void setPosition(sf::Vector2f) = 0;

    protected:
        sf::RectangleShape shape;
};