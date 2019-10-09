#ifndef ADDRESSPROCESSOR_H
#define ADDRESSPROCESSOR_H
#include "address.h"

class AddressProcessor
{
private:
    Address _address;

    bool areSpaces() const;
    std::string removeSpacesOnOneString();

    bool isHTTPprefix() const;
    Address addHTTPPrefix();
public:
    AddressProcessor();
    AddressProcessor(const std::string& _address) : _address(_address){}
    AddressProcessor removeSpaces();
    Address getAddressWithHTTPprefix();

    Address address() const { return _address;}


};

#endif // ADDRESSPROCESSOR_H
