#include "Object.h"
#include <SFML/Graphics.hpp>

Object::Object(const rapidjson::GenericValue<rapidjson::UTF8<> >* d)
{
    std::cout << "OBJECT, YO!" << std::endl;
    // POINTER HAXURS
    objectName = (*d)["nom"].GetString();
    objectSize = (*d)["size"].GetString() == "small" ? SMALL : BIG;
    isContainer = (*d)["is_container"].GetBool();
    isMovable = (*d)["is_movable"].GetBool();

    std::cout << objectName << std::endl << objectSize << std::endl << isContainer << std::endl << isMovable << std::endl;
}

void Object::setPosition(sf::Vector2f pos) {
	position = pos;	
}

void Object::setObjectName(std::string nom) {
	objectName = nom;	
}
   
void Object::setLocationInObject(std::string obj) {
	inObject = true;
}

void Object::setObjectSize(Size s) {
	objectSize = s;
}

void Object::setIsContainer(bool isCont) {
	isContainer = isCont;
}

void Object::setIsMovable(bool isMov) {
	isMovable = isMov;
}

void Object::setInitStates(std::vector<std::string> ei) {
	initStates = ei;
}

void Object::setPossibleStates(std::vector<std::vector<std::string> > ps) {
	possibleStates = ps;
}

void Object::addInteraction(DoesInteract di) {
	interactionsAvailable.insert(std::pair<std::string, DoesInteract>(di.name, di));
}

void Object::addInteraction(RecievesInteract ri) {
	interactionsRecievable.insert(std::pair<std::string, RecievesInteract>(ri.name, ri));
}

bool Object::canInteractWithAction(std::string act) {
	return (interactionsRecievable.count(act) != 0);
}

void Object::applyInteraction(std::string action) {

}

