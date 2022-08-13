#include <string>
#include <vector>
#include <iostream>
#include <sstream>

// #include "../header/JSON_output.h"
#include "../header/WriteFile.h"

class JsonObject
{
public:
    struct Object;

    struct Object
    {
        std::string key;
        std::vector<Object> object;
        size_t size = 0;
        Object(std::string key, std::vector<Object> object) : key(key), object(object) {}
        Object(std::string key, std::vector<Object> object, size_t size) : key(key), object(object), size(size) {}
        Object(std::string key) : key(key) {}
    };

private:
    std::stringstream body;
    size_t size = 0;

    void Insert(Object obj)
    {

        if (size == 0)
            body << "{";

        if (size++ != 0)
            body << ",";

        body << "\n\t " << obj.key << ": ";

        bool addParanteses = obj.size > 0;

        if (addParanteses)
            body << "{";

        // size_t counter = 0;
        for (auto x : obj.object)
        {
            body << x.key;
        }

        if (addParanteses)
            body << "}";
    }

public:
    JsonObject() {}

    Object CreateObject(std::string key, std::vector<Object> object)
    {
        return Object(key, object, object.size());
    }

    Object CreateObject(std::string key, std::string value)
    {
        return Object(key, {Object(value)});
    }

    Object CreateObject(std::string key, std::vector<std::string> values)
    {
        std::vector<Object> object;
        for (auto x : values)
        {
            object.push_back(x);
        }
        return Object(key, object, object.size());
    }

    const Object CreateObject(std::string key, Object &obj) const
    {
        return Object(key, {Object(obj)});
    }

    Object CreateObject(std::string key)
    {
        return Object(key);
    }

    const void InsertObject(const Object &obj)
    {
        Insert(obj);
    }

    const std::string GetBody()
    {
        body << "\n}";
        return body.str();
    }
};

int main()
{

    // WriteFile("test.txt", "bla");

    JsonObject json;
    JsonObject::Object obj1 = json.CreateObject("keys1", std::string("values"));
    JsonObject::Object obj2 = json.CreateObject("keys2", std::vector<std::string>{"values1", "values2"});
    JsonObject::Object obj3 = json.CreateObject("keys3", obj2);

    json.InsertObject(obj1);
    json.InsertObject(obj2);
    json.InsertObject(obj3);

    std::cout << json.GetBody() << std::endl;
}