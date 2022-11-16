#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../include/BlockPoint.h"
#include "../include/Snake.h"

class Game{
    public:
        sf::RenderWindow window;
        Game(int width, int height, std::string window_title, int pointPadding=50, int pointSize=10, sf::Color snakeColor = sf::Color::Red, sf::Color pointColor = sf::Color::Green, std::string fontPath = "fonts/Pointless.ttf", std::string soundPath = "sounds/mainsong.wav", std::string pointSoundPath = "sounds/getPointSound.wav", int volume = 10, float pitch = 0.8);
        bool run();
    private:
        int width;
        int height;
        int pointPadding;
        sf::Vector2u surfaceToDrawPointPosition;
        sf::Event event;
        sf::Clock clock;
        sf::Font font;
        sf::Text text;
        sf::Time elapsed, threshold = sf::seconds(0.1);
        sf::Sound sound;
        sf::Sound pointSound;
        sf::SoundBuffer soundBuffer;
        sf::SoundBuffer pointSoundBuffer;

        Snake* snake;
        BlockPoint* blockPoint;

        std::string fontPath;

        int volume;
        int pitch;

        bool loadFont(std::string);
        void setPointsText();
        bool loadSound(std::string);
        void setSounds(int, float);
};