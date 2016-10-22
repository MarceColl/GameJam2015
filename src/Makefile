
CC=g++
FLAGS=-std=c++11 -Wall
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: GJ2015.o Object.o Game.o Body.o Resources.o Player.o Environment.o main.cpp
	$(CC) $(FLAGS) main.cpp Game.o GJ2015.o Object.o Resources.o Player.o Body.o Environment.o -o GJ2015 $(LIBS)

Resources.o: Resources.cpp Resources.h
	$(CC) $(FLAGS) -c Resources.cpp -o Resources.o

Player.o: Player.cpp Player.h Resources.h
	$(CC) $(FLAGS) -c Player.cpp -o Player.o

Environment.o: Environment.cpp Environment.h Resources.h
	$(CC) $(FLAGS) -c Environment.cpp -o Environment.o

Body.o: Body.cpp Body.h Object.h
	$(CC) $(FLAGS) -c Body.cpp -o Body.o
Game.o: Game.cpp Game.h
	$(CC) $(FLAGS) -c Game.cpp -o Game.o

GJ2015.o: GJ2015.cpp GJ2015.h
	$(CC) $(FLAGS) -c GJ2015.cpp -o GJ2015.o

Object.o: Object.cpp Object.h
	$(CC) $(FLAGS) -c Object.cpp -o Object.o

clean:
	rm *.o
	rm GJ2015
