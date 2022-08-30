g++ -c app/main.cpp src/Block.cpp src/Snake.cpp
g++ main.o Block.o Snake.o -o main-sfml-app.out -lsfml-graphics -lsfml-window -lsfml-system
./main-sfml-app.out
