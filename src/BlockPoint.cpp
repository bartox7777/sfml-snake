#include <cstdlib>
#include <iostream>

#include "../include/BlockPoint.h"

BlockPoint::BlockPoint(sf::Vector2f position, sf::Vector2f size, sf::Color color) : Block(position, size, color), size(size){
    shape.setFillColor(color);
    shape.setPosition(position);
}

BlockPoint::BlockPoint(sf::Vector2u windowSize, sf::Vector2f size, sf::Color color) : Block(sf::Vector2f(), size, color), size(size){
    shape.setFillColor(color);
    setRandomPosition(windowSize);
}

void BlockPoint::setRandomPosition(sf::Vector2u windowSize){
    srand(time(NULL));
    shape.setPosition(sf::Vector2f(size.x * (rand() % int(windowSize.x / size.x)), size.y * (rand() % int(windowSize.y / size.y))));
}