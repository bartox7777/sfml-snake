#include <iostream>

#include "../include/Game.h"
#include "../include/Menu.h"
// #include <SFML/Window.hpp>
// #include <SFML/Audio.hpp>

// #include "../include/BlockPoint.h"
// #include "../include/Snake.h"

using namespace std;

int main(){
    Game game(800, 600, "Wonsz");
    Menu menu(game);
    menu.draw();
    // game.run();
}