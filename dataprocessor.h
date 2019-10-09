#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <address.h>
#include <vector>
#include <fstream>
class DataProcessor
{
private:
    std::ifstream file;
    std::string filename;
    std::vector<Address> readData();
    std::vector<Address> orderData();
    bool compareAddreses(const std::string&, const std::string&) const;
public:
    DataProcessor() : file(), filename() {}
    DataProcessor(std::string _filename) : file(_filename), filename(_filename) {}

    std::vector<Address> getAddressesList();
    void writeAddressList(const std::vector<Address>&) const;
};

#endif // DATAPROCESSOR_H
