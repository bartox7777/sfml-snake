#include <iostream>

#include <SFML/Window.hpp>

#include "../include/BlockPoint.h"
#include "../include/Snake.h"

using namespace std;

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    Snake snake(sf::Vector2f(window.getSize().x/2, window.getSize().y/2), sf::Vector2f(10, 10), sf::Color::Red);
    sf::Event event;
    sf::Clock clock;
    sf::Time elapsed, threshold = sf::seconds(0.1);
    BlockPoint bp(window.getSize(), sf::Vector2f(10, 10), sf::Color::Green);

    srand(time(NULL));

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
        bp.draw(window);
        if (clock.getElapsedTime().asSeconds() > threshold.asSeconds()){
            snake.move();
            clock.restart();
        }
        window.display();
        if (snake.isCollidingWithItself() || snake.isCollidingWithWall(window.getSize())){
                cout << "You lose!" << endl;
                return 0;
        }
        if (snake.isCollidingWithBlock(&bp)){
            snake.addBlock();
            threshold = sf::seconds(threshold.asSeconds() * 0.99);
            bp.setRandomPosition(window.getSize());
            snake.points++;
        }
    }
}