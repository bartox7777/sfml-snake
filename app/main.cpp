#include <iostream>

#include "../include/Game.h"
#include "../include/Menu.h"

using namespace std;

int main(){
    // other resolutions are not supported at the moment, mainly because of the way of drawing points and its padding
    // TODO: make it work with other resolutions
    Game game(800, 600, "Wonsz");
    Menu menu(game);
    menu.draw();
}