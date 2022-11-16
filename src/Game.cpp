#include <iostream>

#include "../include/Game.h"

using namespace std;

Game::Game(int width, int height, string window_title, int pointPadding, int pointSize, sf::Color snakeColor, sf::Color pointColor, string fontPath, string soundPath, string pointSoundPath, int volume, float pitch){
    this->width = width;
    this->height = height;
    window.create(sf::VideoMode(width, height), window_title);

    this->pointPadding = pointPadding;
    this->surfaceToDrawPointPosition = window.getSize() - sf::Vector2u(pointPadding, pointPadding);

    this->snake = new Snake(sf::Vector2f(width/2, height/2), sf::Vector2f(pointSize, pointSize), snakeColor);
    this->blockPoint = new BlockPoint(surfaceToDrawPointPosition, sf::Vector2f(pointSize, pointSize), pointColor);

    loadFont(fontPath);
    loadSound(soundPath);
    loadSound(pointSoundPath);
}

bool Game::run(){
    setSounds(volume, pitch);
    setPointsText();
    this->snake->addBlock();

    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::KeyPressed){
                switch (event.key.code){
                    case sf::Keyboard::Up:
                        if (snake->getDirection() == Block::direction::DOWN || snake->isThereBlock(snake->getHeadPosition() + sf::Vector2f(0, -10))){
                            break;
                        }
                        snake->setDirection(Block::direction::UP);
                        break;
                    case sf::Keyboard::Down:
                        if (snake->getDirection() == Block::direction::UP || snake->isThereBlock(snake->getHeadPosition() + sf::Vector2f(0, 10))){
                            break;
                        }
                        snake->setDirection(Block::direction::DOWN);
                        break;
                    case sf::Keyboard::Left:
                        if (snake->getDirection() == Block::direction::RIGHT || snake->isThereBlock(snake->getHeadPosition() + sf::Vector2f(-10, 0))){
                            break;
                        }
                        snake->setDirection(Block::direction::LEFT);
                        break;
                    case sf::Keyboard::Right:
                        if (snake->getDirection() == Block::direction::LEFT || snake->isThereBlock(snake->getHeadPosition() + sf::Vector2f(10, 0))){
                            break;
                        }
                        snake->setDirection(Block::direction::RIGHT);
                        break;
                }
            }
        }

        window.clear();
        window.draw(text);
        snake->draw(window);
        blockPoint->draw(window);
        if (clock.getElapsedTime().asSeconds() > threshold.asSeconds()){
            snake->move();
            clock.restart();
        }
        window.display();
        if (snake->isCollidingWithItself() || snake->isCollidingWithWall(window.getSize())){
                cout << "You lose!" << endl;
                cout << "Points: " << snake->points << endl;
                return true;
        }
        if (snake->isCollidingWithBlock(blockPoint)){
            pointSound.play();
            snake->addBlock();
            threshold = sf::seconds(threshold.asSeconds() * 0.98);
            sound.setPitch(sound.getPitch() + 0.03);
            blockPoint->setRandomPosition(surfaceToDrawPointPosition);
            snake->points++;
            text.setString("Points: " + to_string(snake->points));
        }
    }
    return false;
}

bool Game::loadFont(string fontPath){
    if(!font.loadFromFile(fontPath)){
        cout << "Error loading font" << endl;
        return false;
    }
    return true;
}

void Game::setPointsText(){
    text.setFont(font);
    text.setString("Points: " + to_string(snake->points));
    text.setPosition(10, 10);
}

bool Game::loadSound(string soundPath){
    if(!soundBuffer.loadFromFile(soundPath)){
        cout << "Error loading sound" << endl;
        return false;
    }
    return true;
}

void Game::setSounds(int volume=10, float pitch=0.8){
    sound.setBuffer(soundBuffer);
    sound.setLoop(true);
    sound.setVolume(volume);
    sound.setPitch(pitch);

    pointSound.setBuffer(pointSoundBuffer);
    pointSound.setVolume(volume);
}