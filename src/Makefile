
CC=g++

all: GJ2015 Object Game 
	$(CC) main.cpp Game.o GJ2015.o Object.o -o GJ2015 -lsfml-graphics -lsfml-window -lsfml-system

Game: Game.h Game.cpp
	$(CC) -c Game.cpp

GJ2015: GJ2015.h GJ2015.cpp
	$(CC) -c GJ2015.cpp

Object: Object.h Object.cpp
	$(CC) -c Object.cpp

clean:
	rm *.o