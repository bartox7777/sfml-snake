#include <SFML/Graphics.hpp>

class Block{
    public:
        Block(sf::Vector2f, sf::Vector2f, sf::Color = sf::Color::White);
        void draw(sf::RenderTarget&) const;
    private:
        sf::RectangleShape shape;
};
