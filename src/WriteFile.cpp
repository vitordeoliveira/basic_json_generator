#include <string>
#include <fstream>
#include <stdexcept>

void WriteFile(std::string filename, std::string data)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        file << data;
        file.close();
    }
    else
        throw std::invalid_argument("Unable to open file");
}
