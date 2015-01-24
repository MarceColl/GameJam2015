#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <vector>
#include <map>
#include <iostream>

#include "include/rapidjson/document.h"
#include <SFML/Graphics.hpp>

enum Size { BIG, SMALL };

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

struct EvalValues {
    double murder;
    double suicide;
    double accident;
    double disappearance;
};

struct MultipliersValues {
    double protagonistImplication;
    double neighborImplication;
    double suicide;
    double accident;
    double disappearance;
};

class GJ2015;
class Object
{
public:
    Object(const rapidjson::GenericValue<rapidjson::UTF8<> >* d);

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
    std::vector<std::string> possibleStates;

    std::map<std::string, DoesInteract> interactionsAvailable;
    std::map<std::string, RecievesInteract> interactionsRecievable;

    std::map<std::string, EvalValues> evalValues;
    std::map<std::string, MultipliersValues> multipliersValues;

    void draw();

    void actsOn(Object* b);

	void setPosition(sf::Vector2f pos);
    void setLocationInObject(std::string obj);
	
	bool canInteractWithAction(std::string act);
	
	void applyInteraction(std::string act);

private:
    void addInteraction(DoesInteract di);
    void addInteraction(RecievesInteract ri);
};

#endif // OBJECT_HPP
