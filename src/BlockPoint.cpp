#include <cstdlib>
#include <iostream>

#include "../include/BlockPoint.h"

BlockPoint::BlockPoint(sf::Vector2f position, sf::Vector2f size, sf::Color color, int padding) : Block(position, size, color), size(size), padding(padding){
    shape.setFillColor(color);
    shape.setPosition(position);
}

BlockPoint::BlockPoint(sf::Vector2u windowSize, sf::Vector2f size, sf::Color color, int padding) : Block(sf::Vector2f(), size, color), size(size), padding(padding){
    shape.setFillColor(color);
    setRandomPosition(windowSize);
}

void BlockPoint::setRandomPosition(sf::Vector2u windowSize){
    srand(time(NULL));
    shape.setPosition(sf::Vector2f((size.x * (rand() % int(windowSize.x / size.x)))+((int)padding/20)*10, (size.y * (rand() % int(windowSize.y / size.y)))+((int)padding/20)*10));
}