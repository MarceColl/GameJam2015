#include "Resources.h"

sf::Texture  Resources::room1Text;
sf::Image    Resources::room1Mask;
sf::Texture  Resources::room2Text;
sf::Image    Resources::room2Mask;
sf::Texture  Resources::player;
sf::Font     Resources::menuFont;

void Resources::load() {
    room1Text.loadFromFile("../assets/room1.png");
    room2Text.loadFromFile("../assets/room2.png");
    room1Mask.loadFromFile("../assets/room1-mask.png");
    room2Mask.loadFromFile("../assets/room2-mask.png");

    player.loadFromFile("../assets/protagonist.png");

    menuFont.loadFromFile("../assets/font.ttf");
}