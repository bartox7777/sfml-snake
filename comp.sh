g++ -c app/main.cpp src/Block.cpp src/Snake.cpp src/BlockPoint.cpp src/Game.cpp src/Menu.cpp
g++ main.o Block.o Snake.o BlockPoint.o Game.o Menu.o -o main-sfml-app.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
./main-sfml-app.out
