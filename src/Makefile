
CC=g++
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: GJ2015.o Object.o Game.o Body.o Resources.o Environment.o main.cpp 
	$(CC) main.cpp Game.o GJ2015.o Object.o Resources.o Body.o Environment.o -o GJ2015 $(LIBS)

Resources: Resources.cpp
	$(CC) -c Resources.cpp -o Resources.o

Environment: Environment.cpp
	$(CC) -c Environment.cpp -o Environment.o

Body: Body.cpp
	$(CC) -c Body.cpp -o Body.o
Game: Game.cpp
	$(CC) -c Game.cpp -o Game.o

GJ2015: GJ2015.cpp
	$(CC) -c GJ2015.cpp -o GJ2015.o

Object: Object.cpp
	$(CC) -c Object.cpp -o Object.o

clean:
	rm *.o
	rm GJ2015