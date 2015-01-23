#include <iostream>
#include <fstream>
#include <vector>

#include "../include/rapidjson/reader.h"

using namespace std;
using namespace rapidjson;

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

int main(){
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