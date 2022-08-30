#include "Block.h"

#include <vector>

class BlockPoint : public Block{
    public:
        BlockPoint(sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color::Green);
        BlockPoint(sf::Vector2u windowSize, sf::Vector2f size, sf::Color color = sf::Color::Green);
        void setRandomPosition(sf::Vector2u sizeOfWindow);
    private:
        sf::Vector2f size;
};