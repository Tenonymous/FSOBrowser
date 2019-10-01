#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <string>
#include <vector>
#include <fstream>
class DataProcessor
{
private:
    std::ifstream file;
public:
    DataProcessor() : file() {}
    DataProcessor(std::string _filename) : file(_filename) {}


    std::vector<std::string> getAddressesList();
};

#endif // DATAPROCESSOR_H
