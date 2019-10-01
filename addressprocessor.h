#ifndef ADDRESSPROCESSOR_H
#define ADDRESSPROCESSOR_H
#include "string"
class AddressProcessor
{
private:
    std::string _address;

    bool areSpaces() const;
    std::string removeSpacesOnOneString();

    bool isHTTPprefix() const;
    std::string addHTTPPrefix();
public:
    AddressProcessor();
    AddressProcessor(const std::string& _address) : _address(_address){}
    AddressProcessor removeSpaces();
    std::string getAddressWithHTTPprefix();

    std::string address() const { return _address;}


};

#endif // ADDRESSPROCESSOR_H
