#include "../include/Block.h"

Block::Block(sf::Vector2f position, sf::Vector2f size, sf::Color color, direction blockDirection) : shape(size), blockDirection(blockDirection){
    shape.setPosition(position);
    shape.setFillColor(color);
}

void Block::draw(sf::RenderTarget& target) const{
    target.draw(shape);
}

sf::Vector2f Block::getPosition() const{
    return shape.getPosition();
}

void Block::setPosition(sf::Vector2f position){
    shape.setPosition(position);
}

Block::direction Block::getDirection() const{
    return blockDirection;
}

void Block::setDirection(direction direction){
    blockDirection = direction;
}