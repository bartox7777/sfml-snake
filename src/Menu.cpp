#include "../include/Menu.h"
#include "../include/Game.h"

Menu::Menu(Game& game) : window(game.window), game(game) {}

void Menu::draw(){
    sf::RectangleShape rectangleStart(sf::Vector2f(window.getSize().x/2, window.getSize().y/6));
    // sf::RectangleShape rectangleScoreboard(sf::Vector2f(window.getSize().x/2, window.getSize().y/6));
    rectangleStart.setPosition(window.getSize().x/2 - rectangleStart.getSize().x/2, window.getSize().y/2 - rectangleStart.getSize().y/2 + 100);
    rectangleStart.setFillColor(sf::Color::Cyan);
    // rectangleScoreboard.setPosition(window.getSize().x/2 - rectangleScoreboard.getSize().x/2, window.getSize().y/2 - rectangleScoreboard.getSize().y/2 + rectangleStart.getSize().y+25);
    // rectangleScoreboard.setFillColor(sf::Color::Cyan);

    sf::Text textStart("Start", game.font, rectangleStart.getSize().y/3);
    textStart.setPosition(rectangleStart.getPosition().x + rectangleStart.getSize().x/2 - textStart.getGlobalBounds().width/2, rectangleStart.getPosition().y + rectangleStart.getSize().y/2 - textStart.getGlobalBounds().height/2);
    // sf::Text textScoreboard("Scoreboard", game.font, rectangleScoreboard.getSize().y/3);
    // textScoreboard.setPosition(rectangleScoreboard.getPosition().x + rectangleScoreboard.getSize().x/2 - textScoreboard.getGlobalBounds().width/2, rectangleScoreboard.getPosition().y + rectangleScoreboard.getSize().y/2 - textScoreboard.getGlobalBounds().height/2);

    sf::Text textTitle("Wonsz", game.font, window.getSize().y/6);
    textTitle.setPosition(window.getSize().x/2 - textTitle.getGlobalBounds().width/2, window.getSize().y/2 - textTitle.getGlobalBounds().height/2 - rectangleStart.getSize().y);

    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    if (event.mouseButton.x >= rectangleStart.getPosition().x && event.mouseButton.x <= rectangleStart.getPosition().x + rectangleStart.getSize().x && event.mouseButton.y >= rectangleStart.getPosition().y && event.mouseButton.y <= rectangleStart.getPosition().y + rectangleStart.getSize().y){
                        game.run();
                        game.sound.stop();
                    }
                    // if (event.mouseButton.x >= rectangleScoreboard.getPosition().x && event.mouseButton.x <= rectangleScoreboard.getPosition().x + rectangleScoreboard.getSize().x && event.mouseButton.y >= rectangleScoreboard.getPosition().y && event.mouseButton.y <= rectangleScoreboard.getPosition().y + rectangleScoreboard.getSize().y){
                    //     // scoreboard
                    // }
                }
            }
        }

        window.clear();
        window.draw(rectangleStart);
        // window.draw(rectangleScoreboard);
        window.draw(textStart);
        // window.draw(textScoreboard);
        window.draw(textTitle);
        window.display();
    }
}