#include <SFML/Graphics.hpp>

class Block{
    public:
        enum direction{
            UP,
            DOWN,
            LEFT,
            RIGHT
        };

        Block(sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color::White, direction blockDirection = direction::UP);
        void draw(sf::RenderTarget& target) const;
        sf::Vector2f getPosition() const;
        direction getDirection() const;
    private:
        sf::RectangleShape shape;
        direction blockDirection;
};
