g++ -c app/main.cpp src/Block.cpp src/Snake.cpp src/BlockPoint.cpp
g++ main.o Block.o Snake.o BlockPoint.o -o main-sfml-app.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
./main-sfml-app.out
