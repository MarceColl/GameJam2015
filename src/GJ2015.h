#ifndef MYGAME_H
#define MYGAME_H
#include "Game.hpp"
#include "Object.h"
#include <string>

class Object;
class GJ2015 : public Game {
public:
    GJ2015(int scrwidth, int scrheight, std::string title, int style);
    ~GJ2015();

    void init();
    void update(float deltaTime);
    void draw();

    void processEvents();
private:
    std::list<Object*> objects;

    bool parseObjectsFile();
};

#endif // MYGAME_H
