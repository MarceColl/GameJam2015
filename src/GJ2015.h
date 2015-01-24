#ifndef MYGAME_H
#define MYGAME_H
#include "Game.h"
#include "Object.h"
#include "Body.h"
#include "Environment.h"
#include "Player.h"
#include <string>
#include <list>

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
    Body* body;

    float timer;

    Environment env;
    Player player;
    
    bool parseObjectsFile();
};

#endif // MYGAME_H
