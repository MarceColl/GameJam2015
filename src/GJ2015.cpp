#include "GJ2015.hpp"
#include "Object.hpp"

#include "include/rapidjson/reader.h"

GJ2015::GJ2015(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style)
    , gameState(menu)
    , ui(this){
    ui.init();
    srand (time(NULL));
}

GJ2015::~GJ2015() {}

void GJ2015::init() {
    std::ifstream file("../Objects.json");
    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    char* buffer = new char[size];
    if (file.read(buffer, size))
    {
        rapidjson::Reader d;

        ObjectJSONHandler handler;
        StringStream ss(buffer);
        d.Parse(ss, handler);
    }

    file.close();
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

GJ2015::ObjectJSONHandler {
        bool Null() {return true;};
        bool Int(int i) { cout << "Int(" << i << ")" << endl; return true; }
        bool Uint(unsigned u) { cout << "Uint(" << u << ")" << endl; return true; }
        bool Int64(int64_t i) { cout << "Int64(" << i << ")" << endl; return true; }
        bool Uint64(uint64_t u) { cout << "Uint64(" << u << ")" << endl; return true; }

        // JSON Basic Types
        bool Bool(bool b) { cout << "Bool(" << boolalpha << b << ")" << endl; return true; }
        bool Double(double d) { cout << "Double(" << d << ")" << endl; return true; }
        bool String(const char* str, SizeType length, bool copy) { 
            cout << str << endl;
            return true;
        }

        // JSON Object
        bool StartObject() { cout << "{" << endl; return true; }
        bool Key(const char* str, SizeType length, bool copy) {
            cout << str << ": ";
            return true;
        }
        bool EndObject(SizeType memberCount) { cout << "}" << endl; return true; }

        // JSON Array
        bool StartArray() { cout << "[" << endl; return true; }
        bool EndArray(SizeType elementCount) { cout << "]" << endl; return true; }
    };
