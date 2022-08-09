#include <string>
#include <vector>
#include <iostream>
#include <sstream>

// #include "../header/JSON_output.h"
#include "../header/WriteFile.h"

class JsonObject
{
private:
    std::vector<std::string> body;
    size_t size;

    // struct Object;

    struct Object
    {
        std::string key;
        std::vector<std::string> values;
        // Object *objs;
        Object(std::string key, std::vector<std::string> values) : key(key), values(values) {}

        
    };

    void insert(Object obj)
    {
        std::stringstream ss;

        ss << "\t " << obj.key << ": " << "value";
        body.push_back(ss.str());
    }

public:
    JsonObject() : body({"{\n"})
    {
        insert(Object("name", {"vitor"}));
    }

    JsonObject(Object obj) {}

    void CreateObject(Object obj)
    {
    }

    void CreateObject(std::string key, std::vector<std::string> values)
    {
    }

    const std::string GetBody() const
    {
        std::stringstream buffer;

        for (auto i : body)
        {
            buffer << i;
        }

        buffer << "\n}";
        return buffer.str();
    }
};

// std::string JSON_generator(const JsonObject &&keys)
// {
//     std::stringstream buffer;

//     buffer << "{\n\t" << keys.GetKey() << ":";

//     return buffer.str();
// }

int main()
{

    // WriteFile("test.txt", "bla");
    JsonObject json;
    // Now Object is private
    // json.CreateObject(JsonObject::Object("keys", {"value", "value1"}));
    json.CreateObject("keys1", {"value", "value1"});

    std::cout << json.GetBody() << std::endl;
}