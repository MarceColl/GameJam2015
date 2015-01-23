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


void addInteraction(DoesInteract di){

interactionsAvailable.insert(std::pair<std::string,DoesInteract>(di.name,di))

}

void addInteraction(RecievesInteract ri){

interactionsRecievable.insert( std::pair<std::string ,DoesInteract>(ri.name,ri))

}

