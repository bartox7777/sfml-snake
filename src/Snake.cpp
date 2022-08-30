#include "../include/Snake.h"

Snake::Snake(sf::Vector2f position, sf::Vector2f sizeOfBlock, sf::Color color) : sizeOfBlock(sizeOfBlock), color(color){
    blocks.push_back(new Block(position, sizeOfBlock, color));
}

void Snake::draw(sf::RenderTarget& target) const{
    for (auto block : blocks){
        block->draw(target);
    }
}

void Snake::move(){
    for (int i=blocks.size()-1; i>=0; i--){
        switch (blocks[i]->getDirection()){
            case Block::direction::UP:
                blocks[i]->setPosition(sf::Vector2f(blocks[i]->getPosition().x, blocks[i]->getPosition().y - sizeOfBlock.y));
                break;
            case Block::direction::DOWN:
                blocks[i]->setPosition(sf::Vector2f(blocks[i]->getPosition().x, blocks[i]->getPosition().y + sizeOfBlock.y));
                break;
            case Block::direction::LEFT:
                blocks[i]->setPosition(sf::Vector2f(blocks[i]->getPosition().x - sizeOfBlock.x, blocks[i]->getPosition().y));
                break;
            case Block::direction::RIGHT:
                blocks[i]->setPosition(sf::Vector2f(blocks[i]->getPosition().x + sizeOfBlock.x, blocks[i]->getPosition().y));
                break;
        }
        if (i != 0){
            blocks[i]->setDirection(blocks[i-1]->getDirection());
        }
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

bool Snake::isThereBlock(sf::Vector2f position) const{
    for (auto block : blocks){
        if (block->getPosition() == position){
            return true;
        }
    }
    return false;
}

Block::direction Snake::getDirection() const{
    return blocks[0]->getDirection();
}

void Snake::setDirection(Block::direction direction){
    blocks[0]->setDirection(direction);
}

sf::Vector2f Snake::getHeadPosition() const{
    return blocks[0]->getPosition();
}

bool Snake::isCollidingWithItself() const{
    for (int i = 1; i < blocks.size(); i++){
        if (getHeadPosition() == blocks[i]->getPosition()){
            return true;
        }
    }
    return false;
}

bool Snake::isCollidingWithWall(sf::Vector2f sizeOfWindow) const{
    if (getHeadPosition().x < 0 || getHeadPosition().x > sizeOfWindow.x){
        return true;
    }
    if (getHeadPosition().y < 0 || getHeadPosition().y > sizeOfWindow.y){
        return true;
    }
    return false;
}