#include <iostream>

#include <SFML/Window.hpp>

// #include "../include/Block.h"
#include "../include/Snake.h"

using namespace std;

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    Snake snake(sf::Vector2f(window.getSize().x/2, window.getSize().y/2), sf::Vector2f(10, 10), sf::Color::Red);
    sf::Event event;
    snake.addBlock();

    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear();
        snake.draw(window);
        window.display();
    }
}