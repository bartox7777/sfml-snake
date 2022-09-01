#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "../include/BlockPoint.h"
#include "../include/Snake.h"

using namespace std;

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    sf::Event event;
    sf::Clock clock;
    sf::Font font;
    sf::Text text;
    sf::Time elapsed, threshold = sf::seconds(0.1);
    sf::Sound sound;
    sf::SoundBuffer soundBuffer;

    Snake snake(sf::Vector2f(window.getSize().x/2, window.getSize().y/2), sf::Vector2f(10, 10), sf::Color::Red);
    BlockPoint bp(window.getSize(), sf::Vector2f(10, 10), sf::Color::Green);

    snake.addBlock();

    if(!font.loadFromFile("fonts/Pointless.ttf")){
        cout << "Error loading font" << endl;
        return -1;
    }
    text.setFont(font);
    text.setString("Points: " + to_string(snake.points));
    text.setPosition(10, 10);

    if(!soundBuffer.loadFromFile("sounds/mainsong.wav")){
        cout << "Error loading sound" << endl;
        return -1;
    }
    sound.setBuffer(soundBuffer);

    sound.play();

    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::KeyPressed){
                switch (event.key.code){
                    case sf::Keyboard::Up:
                        if (snake.getDirection() == Block::direction::DOWN || snake.isThereBlock(snake.getHeadPosition() + sf::Vector2f(0, -10))){
                            break;
                        }
                        snake.setDirection(Block::direction::UP);
                        break;
                    case sf::Keyboard::Down:
                        if (snake.getDirection() == Block::direction::UP || snake.isThereBlock(snake.getHeadPosition() + sf::Vector2f(0, 10))){
                            break;
                        }
                        snake.setDirection(Block::direction::DOWN);
                        break;
                    case sf::Keyboard::Left:
                        if (snake.getDirection() == Block::direction::RIGHT || snake.isThereBlock(snake.getHeadPosition() + sf::Vector2f(-10, 0))){
                            break;
                        }
                        snake.setDirection(Block::direction::LEFT);
                        break;
                    case sf::Keyboard::Right:
                        if (snake.getDirection() == Block::direction::LEFT || snake.isThereBlock(snake.getHeadPosition() + sf::Vector2f(10, 0))){
                            break;
                        }
                        snake.setDirection(Block::direction::RIGHT);
                        break;
                }
            }
        }

        window.clear();
        window.draw(text);
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
            text.setString("Points: " + to_string(snake.points));
        }
    }
}