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

bool canInteractWithAction(std::sting act){
	return (interactionsRecievable.count(act)!=0);
}

void applyInteraction(std::sting action){

	RecievesInteract act = interactionsRecievable.get(action);
	
	std::vector<StateChange> modificacions= act.canvisEstat;
	
	for (std::vector<StateChange>::iterator it = modificacions.begin(); it != modificacions.end(); ++it){
		
		
	
	}
	
	
	

}

