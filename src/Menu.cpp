#include "../include/Menu.h"
#include "../include/Game.h"

Menu::Menu(Game& game) : window(game.window), game(game) {}

void Menu::draw(){
    sf::RectangleShape rectangleStart(sf::Vector2f(window.getSize().x/2, window.getSize().y/6));
    rectangleStart.setPosition(window.getSize().x/2 - rectangleStart.getSize().x/2, window.getSize().y/2 - rectangleStart.getSize().y/2 + 100);
    rectangleStart.setFillColor(sf::Color::Cyan);

    sf::Text textStart("Start", game.font, rectangleStart.getSize().y/3);
    textStart.setOrigin(textStart.getLocalBounds().width/2, textStart.getLocalBounds().height/2);
    textStart.setPosition(rectangleStart.getPosition() + rectangleStart.getSize() / 2.f);

    sf::Text textTitle(game.window_title, game.font, window.getSize().y/6);
    textTitle.setPosition(window.getSize().x/2 - textTitle.getGlobalBounds().width/2, window.getSize().y/2 - textTitle.getGlobalBounds().height/2 - rectangleStart.getSize().y);

    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    if (rectangleStart.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
                        game.run();
                    }
                }
            }
        }

        window.clear();
        window.draw(rectangleStart);
        window.draw(textStart);
        window.draw(textTitle);
        window.display();
    }
}