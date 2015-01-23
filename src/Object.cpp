#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "utils.hpp"

class LD48;
class Object
{
public:
    Object(LD48* game, sf::Vector2f size, sf::Texture& tex, sf::Vector2i spriteCount );

    LD48* game;

    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture& tex;
    sf::Vector2i spriteCount;
    sf::Vector2i spriteNum;
    sf::Sprite sprite;

    void draw();

    void actsOn(Object* b);

private:
    bool isInsideObject;
};

#endif // OBJECT_HPP
