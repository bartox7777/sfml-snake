#include "../include/Snake.h"

Snake::Snake(sf::Vector2f position, sf::Vector2f sizeOfBlock, sf::Color color) : sizeOfBlock(sizeOfBlock), color(color){
    blocks.push_back(new Block(position, sizeOfBlock, color));
}

void Snake::draw(sf::RenderTarget& target) const{
    for (auto block : blocks){
        block->draw(target);
    }
}

void Snake::addBlock(){
    sf::Vector2f position = blocks.back()->getPosition();
    Block::direction direction = blocks.back()->getDirection();
    switch (blocks.back()->getDirection()){
        case Block::direction::UP:
            position.y += sizeOfBlock.y;
            break;
        case Block::direction::DOWN:
            position.y -= sizeOfBlock.y;
            break;
        case Block::direction::LEFT:
            position.x += sizeOfBlock.x;
            break;
        case Block::direction::RIGHT:
            position.x -= sizeOfBlock.x;
            break;
    }
    blocks.push_back(new Block(position, sizeOfBlock, color, blocks.back()->getDirection()));
}