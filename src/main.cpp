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
        Object(std::string key, std::vector<Object> object) : key(key), object(object) {}
        Object(std::string key) : key(key) {}
    };

private:
    std::vector<std::string> body;
    size_t size = 0;

    void insert(Object obj)
    {

        std::stringstream ss;
        if (size++ != 0)
            ss << ",";

        ss << "\n\t " << obj.key << ": ";
        for (auto x : obj.object)
        {
            ss << x.key;
        }
        body.push_back(ss.str());
    }

public:
    JsonObject() : body({"{"})
    {
    }

    JsonObject(Object obj) {}

    // void CreateObject(Object obj)
    // {
    // }

    Object CreateObject(std::string key, std::vector<Object> object)
    {
        return Object(key, object);
    }

    Object CreateObject(std::string key, std::string value)
    {
        return Object(key, {Object(value)});
    }

    Object CreateObject(std::string key, Object obj)
    {
        return Object(key, {Object(obj)});
    }

    Object CreateObject(std::string key)
    {
        return Object(key);
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

int main()
{

    // WriteFile("test.txt", "bla");
    JsonObject json;
    // Now Object is private
    // json.CreateObject("keys", JsonObject::Object({"value", "value1"}));
    JsonObject::Object obj1 = json.CreateObject("keys1", "values");
    // json.CreateObject("keys2", "values");
    std::cout << obj1.object[0].key << '\n';

    // std::cout << json.GetBody() << std::endl;
}