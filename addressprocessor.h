#ifndef ADDRESSPROCESSOR_H
#define ADDRESSPROCESSOR_H
#include "string"
class AddressProcessor
{
private:
    std::string address;

    std::string removeSpacesOnOneString(std::string&);
    std::string addHTTPPrefix(std::string&);
public:
    AddressProcessor();
    AddressProcessor(const std::string& _address) : address(_address){}
    bool areSpaces();
    std::string removeSpaces();
    bool isHTTPprefix();
    std::string getAddressWithHTTPprefix();


};

#endif // ADDRESSPROCESSOR_H
