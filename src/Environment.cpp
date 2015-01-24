#include "Environment.h"
#include "Resources.h"
#include <iostream>

Environment::Environment(sf::RenderWindow *wndw) :
        texRoom1(Resources::room1Text), 
        texRoom2(Resources::room2Text),
        texRoom3(Resources::room3Text) {
    currentRoom = 1;
    window = wndw;
    
    spriteRoom1.setTexture(texRoom1);
    spriteRoom1.setPosition(0, 0);

    spriteRoom2.setTexture(texRoom2);
    spriteRoom2.setPosition(0, 0);

    spriteRoom3.setTexture(texRoom3);
    spriteRoom3.setPosition(0, 0);
}

void Environment::draw() {
    sf::Sprite *currentR;
    currentR = currentRoom == 1 ? &spriteRoom1 : currentRoom == 2 ? &spriteRoom2 : &spriteRoom3;
    window->draw(*currentR);
}

int Environment::getCurrentRoom() {
    return currentRoom;
}

Environment::~Environment() {}