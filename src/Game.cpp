#include <iostream>

#include "../include/Game.h"

using namespace std;

Game::Game(int width, int height, string window_title, int pointPadding, int pointSize, sf::Color snakeColor, sf::Color pointColor, string fontPath, string soundPath, string pointSoundPath, int volume, float pitch, float startSpeed){
    this->width = width;
    this->height = height;
    pointSize = ((int)pointSize/10)*10;
    window.create(sf::VideoMode(width, height), window_title);

    this->window_title = window_title;

    this->startSpeed = startSpeed;

    this->pointPadding = pointPadding;
    this->surfaceToDrawPointPosition = window.getSize() - sf::Vector2u(pointPadding, pointPadding);

    this->snake = new Snake(sf::Vector2f(width/2, height/2), sf::Vector2f(pointSize, pointSize), snakeColor);
    this->blockPoint = new BlockPoint(surfaceToDrawPointPosition, sf::Vector2f(pointSize, pointSize), pointColor, pointPadding);

    loadFont(fontPath);
    this->soundPath = soundPath;
    this->pointSoundPath = pointSoundPath;
}

void Game::presetGame(){
    setPointsText();
    snake->reset();
    setSounds();
    sound.play();
    text.setString("Points: " + to_string(snake->points));
    threshold = sf::seconds(this->startSpeed);
}

bool Game::run(){
    presetGame();

    bool gavePoint = false;

    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::KeyPressed){
                // second statment in ifs is an important protection against invalid move, but it's causing that fast moves sometimes are not registered
                // TODO: find better solution
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
            gavePoint = false;
            snake->move();
            clock.restart();
        }
        window.display();
        if (snake->isCollidingWithItself() || snake->isCollidingWithWall(window.getSize())){
                gameLost();
                return true;
        }
        if (snake->isCollidingWithBlock(blockPoint) and not gavePoint){
            gavePoint = true;
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

sf::SoundBuffer Game::loadSound(string soundPath){
    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile(soundPath)){
        cout << "Error loading sound" << endl;
    }
    return buffer;
}

void Game::setSounds(int volume, float pitch){
    soundBuffer = loadSound(soundPath);
    pointSoundBuffer = loadSound(pointSoundPath);

    sound.setBuffer(soundBuffer);
    sound.setLoop(true);
    sound.setVolume(volume);
    sound.setPitch(pitch);

    pointSound.setBuffer(pointSoundBuffer);
    pointSound.setVolume(volume);
}

void Game::gameLost(){
    sound.stop();
    window.clear();
    sf::Text lostText("You lost!", font, 30);
    sf::Text lostTextPoints("Points: " + to_string(snake->points), font, 30);
    lostText.setPosition(width/2 - lostText.getGlobalBounds().width/2, height/2 - lostText.getGlobalBounds().height/2);
    lostTextPoints.setPosition(width/2 - lostTextPoints.getGlobalBounds().width/2, height/2 - lostTextPoints.getGlobalBounds().height/2 + 60);
    window.draw(lostText);
    window.draw(lostTextPoints);
    window.display();
    sf::sleep(sf::seconds(4));
}