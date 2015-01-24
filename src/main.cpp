#include "GJ2015.h"
#include "Resources.h"

int main() {
    Resources::load();
    GJ2015 game(1920, 1080, "What do I do now?", sf::Style::Default);
    game.run();
    return 0;
}