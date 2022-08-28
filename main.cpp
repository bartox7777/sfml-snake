#include <iostream>

#include <SFML/Window.hpp>

#include "Block.h"

using namespace std;

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    Block block(sf::Vector2f(0, 0), sf::Vector2f(10, 10));
    sf::Event event;


    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear();
        block.draw(window);
        window.display();
    }
}