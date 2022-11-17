#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "../include/Block.h"

class Snake{
    friend class Game;
    public:
        Snake(sf::Vector2f position, sf::Vector2f sizeOfBlock, sf::Color color = sf::Color::White, Block::direction headDirection = Block::direction::RIGHT);

        unsigned int points;

        void draw(sf::RenderTarget& target) const;
        void move();

        // method which adds a new block at the end of the snake
        void addBlock();
        bool isThereBlock(sf::Vector2f position) const;

        Block::direction getDirection() const;
        void setDirection(Block::direction direction);

        sf::Vector2f getHeadPosition() const;

        bool isCollidingWithItself() const;
        bool isCollidingWithWall(sf::Vector2u sizeOfWindow) const;
        bool isCollidingWithBlock(Block* blockPoint) const;

        void reset();

        sf::Vector2f startPosition;
    private:
        std::vector<Block*> blocks;
        sf::Vector2f sizeOfBlock;
        sf::Color color;
};