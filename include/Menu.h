#pragma once

#include "SFML/Graphics.hpp"

class Game;
class Menu{
    public:
        Menu(Game& game);
        void draw();
    private:
        Game& game;
        sf::Event event;
        sf::RenderWindow &window;
};