#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include "include/SFML/Graphics.hpp"

class Resources {
public:
    static void load();
    static sf::Texture  room1Text;
    static sf::Image    room1Mask;
    static sf::Texture  room2Text;
    static sf::Image    room2Mask;
    static sf::Texture  player;
    static sf::Font     menuFont;
};

#endif // RESOURCES_HPP