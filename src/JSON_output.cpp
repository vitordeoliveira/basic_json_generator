#pragma once
#include <iostream>

// std::string JSON_generator();
void JSON_generator(const std::string &keys)
{
    std::string exampleArray[] = {"Example", "Example2", "Example3"};
    int num_strings = sizeof(keys) / sizeof(keys[0]);

    std::cout << num_strings << std::endl;
}