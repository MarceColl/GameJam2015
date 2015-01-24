#include <iostream>
#include <fstream>
#include <vector>

#include "../include/rapidjson/document.h"

using namespace std;
using namespace rapidjson;

int main(){
    std::ifstream file("../Objects.json");
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
            printf("%s\n", (*itr)["nom"].GetString());
        }
    }
    else
    {
        std::cerr << "Failed to open Objects.json!" << std::endl;
    }

    file.close();
}