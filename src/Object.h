#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <vector>
#include <map>
#include <iostream>

#include "include/rapidjson/document.h"
#include <SFML/Graphics.hpp>

enum Size { SMALL, BIG };

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
    Object(const rapidjson::GenericValue<rapidjson::UTF8<> >**);

    sf::Vector2f position;
    sf::Vector2f size;
    //sf::Texture& tex;
    sf::Vector2i spriteCount;
    sf::Vector2i spriteNum;
    sf::Sprite sprite;

    Size objectSize;

    bool isContainer;
    bool isMovable;
    bool inObject;
    
    std::string locationInObject;
    std::string objectName;

    std::vector<std::string> initStates;
    std::vector<std::vector<std::string> > possibleStates;

    std::map<std::string, DoesInteract> interactionsAvailable;
    std::map<std::string, RecievesInteract> interactionsRecievable;

    void draw();

    void actsOn(Object* b);

	void setPosition(sf::Vector2f pos);
    void setObjectName(std::string nom);
    void setLocationInObject(std::string obj);
    void setObjectSize(Size s);
    void setIsContainer(bool isCont);
    void setIsMovable(bool isMov);
    void setInitStates(std::vector<std::string> ei);
    void setPossibleStates(std::vector<std::vector<std::string> > ps);

    void addInteraction(DoesInteract di);
    void addInteraction(RecievesInteract ri);
	
	bool canInteractWithAction(std::string act);
	
	void applyInteraction(std::string act);
};

#endif // OBJECT_HPP
