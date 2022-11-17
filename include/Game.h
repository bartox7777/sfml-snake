#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../include/BlockPoint.h"
#include "../include/Snake.h"

class Game{
    friend class Menu;
    public:
        Game(int width, int height, std::string window_title, int pointPadding=100, int pointSize=10, sf::Color snakeColor = sf::Color::Red, sf::Color pointColor = sf::Color::Green, std::string fontPath = "fonts/Pointless.ttf", std::string soundPath = "sounds/mainsong.wav", std::string pointSoundPath = "sounds/getPointSound.wav", int volume = 10, float pitch = 0.8, float startSpeed = 0.1);
        bool run();
    private:
        int width;
        int height;
        int pointPadding;
        sf::Vector2u surfaceToDrawPointPosition;
        sf::Event event;
        sf::Clock clock;
        sf::Text text;
        sf::Time elapsed, threshold;
        sf::Sound sound;
        sf::Sound pointSound;
        sf::SoundBuffer soundBuffer;
        sf::SoundBuffer pointSoundBuffer;
        sf::Font font;
        sf::RenderWindow window;
        float startSpeed;

        void presetGame();

        Snake* snake;
        BlockPoint* blockPoint;

        std::string fontPath;
        std::string soundPath;
        std::string pointSoundPath;

        bool loadFont(std::string);
        void setPointsText();
        sf::SoundBuffer loadSound(std::string);
        void setSounds(int=10, float=0.8);
};