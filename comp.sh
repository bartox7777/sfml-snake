g++ -c main.cpp Block.cpp Snake.cpp
g++ main.o Block.o Snake.o -o main-sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./main-sfml-app
