#include "Object.h"

Object::Object()
{
    inObject=false;
    objectSize=Size.SMALL;

}

Object::Object(string name)
{
    objectName=name;

    inObject=false;
    objectSize=Size.SMALL;

}

Object::~Object()
{
    //dtor
}

void setPosition(sf::Vector2f pos){
	position=pos;	
}

void setObjectName(std::string nom){
	objectName=name;	
}
   
void  setLocationInObject(std::string obj){
	inObject=true;
}

void setObjectSize(Size s){
	objectSize=s;
}

void setIsContainer(bool isCont){
	isContainer=isCont;
}

void setIsMovable(bool isMov){
	isMovable=isMov;
}

void setInitStates(std::vector<std::string> ei){
	initStates=ei;
}

void setPossibleStates(std::vector<std::vector<std::string> > ps){
	possibleStates=ps;
}

void addInteraction(DoesInteract di){
	interactionsAvailable.insert(std::pair<std::string,DoesInteract>(di.name,di));
}

void addInteraction(RecievesInteract ri){

	interactionsRecievable.insert( std::pair<std::string ,DoesInteract>(ri.name,ri));
}


