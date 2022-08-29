#include <vector>

#include <SFML/Graphics.hpp>

#include "../include/Block.h"

class Snake{
    public:
        Snake(sf::Vector2f position, sf::Vector2f sizeOfBlock, sf::Color color = sf::Color::White);

        void draw(sf::RenderTarget& target) const;

        // method which adds a new block at the end of the snake
        void addBlock();
    private:
        std::vector<Block*> blocks;
        sf::Vector2f sizeOfBlock;
        sf::Color color;
};