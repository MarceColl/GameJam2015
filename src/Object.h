#ifndef OBJECT_HPP
#define OBJECT_HPP
//#include "utils.hpp"
#include <vector>
#include <map>

enum Size {SMALL,BIG};

struct StateChange{
    std::string initState;
    std::string finalState;
};

struct DoesInteract{
    std::string name;

    std::string objectModif;//Si buit voldir qualsevol

    std::vector<StateChange> stateChanged;

};

struct RecievesInteract{
    std::string name;

    std::vector<StateChange> canvisEstat;

};

class GJ2015;
class Object
{
public:
    Object(GJ2015* game, sf::Vector2f size, sf::Texture& tex, sf::Vector2i spriteCount );

    GJ2015* game;

    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture& tex;
    sf::Vector2i spriteCount;
    sf::Vector2i spriteNum;
    sf::Sprite sprite;

    void draw();

    void actsOn(Object* b);


    addInteraction(DoesInteract di);

    addInteraction(RecievesInteract ri);

    setObjectName(std::string nom);

    setLocationInObject(string obj);

    setObjectSize(Size s);

    setIsContainer(bool isCont);

    setIsMovable(bool isMov);

    setInitStates(std::vector<std::string> ei);
    setPossibleStates(std::vector<std::vector<std::string> > ps);

private:


    std::string objectName;

    bool inObject;
    std::string locationInObject;

    Size objectSize;

    bool isContainer;

    bool isMovable

    std::vector<std::string> initStates;
    std::vector<std::vector<std::string> > possibleStates;

    std::map<std::string,DoesInteract> interactionsAvailable;

    std::map<std::string,RecievesInteract> interactionsRecievable;


};

#endif // OBJECT_HPP
