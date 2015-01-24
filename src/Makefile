
CC=g++
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: GJ2015.o Object.o Game.o main.cpp
	$(CC) main.cpp Game.o GJ2015.o Object.o -o GJ2015 $(LIBS)

Game: Game.cpp
	$(CC) -c Game.cpp -o Game.o

GJ2015: GJ2015.cpp
	$(CC) -c GJ2015.cpp -o GJ2015.o

Object: Object.cpp
	$(CC) -c Object.cpp -o Object.o

clean:
	rm *.o
	rm GJ2015