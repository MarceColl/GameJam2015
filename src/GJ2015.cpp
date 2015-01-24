#include "GJ2015.hpp"
#include "Object.hpp"

#include "include/rapidjson/document.h"

GJ2015::GJ2015(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style) {
    srand (time(NULL));
}

GJ2015::~GJ2015() {}

void GJ2015::init() {
    if(parseObjectsFile()) {
        std::cout << "File loaded" << std::endl;
    }
    else
    {
        std::cout << "Critical: Couldn't load objects file" << std::endl;
    }
}

bool GJ2015::parseObjectsFile() {
    std::ifstream file("Objects.json");
    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    char* buffer = new char[size];
    if (file.read(buffer, size))
    {
        rapidjson::Document d;
        d.Parse(buffer);

        const rapidjson::Value& objectsJSON = d["objects"];
        for (Value::ConstValueIterator itr = objectsJSON.Begin(); itr != objectsJSON.End(); ++itr) {
            Object* ob = new Object(&itr);
            objects.push_back(ob);
        }
    }
    else
    {
        std::cerr << "Failed to open Objects.json!" << std::endl;
        return false;
    }

    file.close();
    return true;
}

void GJ2015::update(float deltaTime){

}

void GJ2015::draw(){

}

void GJ2015::processEvents(){
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (gameState == playing) keyPressed(event);
                else ui.setKeyPressed(event.key.code);
                break;
            case sf::Event::KeyReleased:
                if (gameState == playing) keyReleased(event);
                break;
            default:
                break;
        }
    }
}

sf::RenderWindow* GJ2015::getWindow() {
    return &window;
}

