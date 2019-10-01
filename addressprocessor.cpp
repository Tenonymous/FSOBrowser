#include "addressprocessor.h"
#include "algorithm"
AddressProcessor::AddressProcessor()
{

}

bool AddressProcessor::areSpaces() const
{
    return _address.find(' ') != std::string::npos;
}
std::string AddressProcessor::removeSpacesOnOneString()
{
    std::string addressWithoutSpaces{};
    std::copy_if(_address.begin(),
                 _address.end(),
                 std::back_inserter(addressWithoutSpaces),
                 [](auto sign){return !std::isspace(sign);});
    return addressWithoutSpaces;
}
AddressProcessor AddressProcessor::removeSpaces()
{
    return areSpaces() ?
                AddressProcessor(removeSpacesOnOneString()) :
                AddressProcessor(_address);
}

bool AddressProcessor::isHTTPprefix() const
{
    return _address.find("http://", 0, 7) == 0;
}

std::string AddressProcessor::addHTTPPrefix()
{  
    return "http://" + _address;
}

std::string AddressProcessor::getAddressWithHTTPprefix()
{
    return isHTTPprefix() ? _address : addHTTPPrefix();
}
