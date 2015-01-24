
all: GJ2015 Object Game 
	gcc-4.9 Game.o GJ2015.o Object.o -o GJ2015

Game: Game.h Game.cpp
	gcc-4.9 -c Game.cpp

GJ2015: GJ2015.h GJ2015.cpp
	gcc-4.9 -c GJ2015.cpp

Object: Object.h Object.cpp
	gcc-4.9 -c Object.cpp

clean:
	rm *.o