#include "include/SFML/Graphics.hpp"

class Environment {
public:
    Environment(sf::RenderWindow *wndw);
    ~Environment();

    void draw();
    void switchRoom(int room);

    int getCurrentRoom();
private:
    sf::RenderWindow *window;

    int currentRoom;

    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture& texRoom1;
    sf::Texture& texRoom2;
    //sf::Texture& texRoom3;
    sf::Sprite spriteRoom1;
    sf::Sprite spriteRoom2;
    sf::Sprite spriteRoom3;
};