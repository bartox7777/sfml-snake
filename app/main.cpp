#include <iostream>

#include <SFML/Window.hpp>

// #include "../include/Block.h"
#include "../include/Snake.h"

using namespace std;

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    Snake snake(sf::Vector2f(window.getSize().x/2, window.getSize().y/2), sf::Vector2f(10, 10), sf::Color::Red);
    sf::Event event;
    sf::Clock clock;
    sf::Time elapsed;

    snake.addBlock();
    snake.addBlock();
    snake.addBlock();
    snake.addBlock();
    snake.addBlock();
    snake.addBlock();
    snake.addBlock();
    snake.addBlock();
    snake.addBlock();
    snake.addBlock();
    snake.addBlock();
    snake.addBlock();
    snake.addBlock();
    snake.addBlock();
    snake.addBlock();

    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::KeyPressed){
                switch (event.key.code){
                    case sf::Keyboard::Up:
                        if (!(snake.getDirection() == Block::direction::DOWN && snake.isThereBlock(snake.getHeadPosition() + sf::Vector2f(0, -10)))){
                            snake.setDirection(Block::direction::UP);
                        }
                        break;
                    case sf::Keyboard::Down:
                        if (!(snake.getDirection() == Block::direction::UP && snake.isThereBlock(snake.getHeadPosition() + sf::Vector2f(0, 10)))){
                            snake.setDirection(Block::direction::DOWN);
                        }
                        break;
                    case sf::Keyboard::Left:
                        if (!(snake.getDirection() == Block::direction::RIGHT && snake.isThereBlock(snake.getHeadPosition() + sf::Vector2f(-10, 0)))){
                            snake.setDirection(Block::direction::LEFT);
                        }
                        break;
                    case sf::Keyboard::Right:
                        if (!(snake.getDirection() == Block::direction::LEFT && snake.isThereBlock(snake.getHeadPosition() + sf::Vector2f(10, 0)))){
                            snake.setDirection(Block::direction::RIGHT);
                        }
                        break;
                }
            }
        }

        window.clear();
        snake.draw(window);
        if (clock.getElapsedTime().asSeconds() > 0.1){
            snake.move();
            clock.restart();
        }
        window.display();
         if (snake.isCollidingWithItself() || snake.isCollidingWithWall(sf::Vector2f(window.getSize().x, window.getSize().y))){
                cout << "You lose!" << endl;
                return 0;
        }
    }
}