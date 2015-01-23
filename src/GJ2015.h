#ifndef MYGAME_H
#define MYGAME_H
#include "Game.hpp"
#include "Object.h"

class Object;
class GJ2015 : public Game {
public:
    GJ2015(int scrwidth, int scrheight, std::string title, int style);
    ~GJ2015();

    void init();
    void update(float deltaTime);
    void draw();

    void processEvents();
private:
    std::list<Object*> objects;

    std::vector<std::vector<dir>> isKeyPressed;

    struct ObjectJSONHandler {
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
};

#endif // MYGAME_H
