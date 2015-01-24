#include "Object.h"
#include <SFML/Graphics.hpp>

Object::Object(const rapidjson::GenericValue<rapidjson::UTF8<> >** d)
{
    // POINTER HAXURS
    objectName = (**d)["name"].GetString();
    objectSize = (**d)["size"].GetString() == "small" ? SMALL : BIG;
    isContainer = (**d)["is_container"].GetBool();
    isMovable = (**d)["is_movable"].GetBool();
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

RecievesInteract act = interactionsRecievable.get(action);
	
	std::vector<StateChange> modificacions= act.canvisEstat;
	
	for (std::vector<StateChange>::iterator it = modificacions.begin(); it != modificacions.end(); ++it){
		std::string initS=it->initState;
		if(initStates.contains(initS)){
			for (std::vector<std::string>::iterator iter = initStates.begin(); iter != initStates.end(); ++iter){
				if(*iter==initS){
					*iter=(it->finalState);
					break;
				}
			}
		}
	}
}

