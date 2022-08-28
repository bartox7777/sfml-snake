#include "Block.h"

Block::Block(sf::Vector2f position, sf::Vector2f size, sf::Color color) : shape(size){
    shape.setPosition(position);
    shape.setFillColor(color);
}

void Block::draw(sf::RenderTarget& target) const{
    target.draw(shape);
}