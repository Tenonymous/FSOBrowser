#include "addressprocessor.h"
#include "algorithm"
AddressProcessor::AddressProcessor()
{

}

bool AddressProcessor::areSpaces() const
{
    return _address.address().find(' ') != std::string::npos;
}
std::string AddressProcessor::removeSpacesOnOneString()
{
    std::string addressWithoutSpaces{};
    std::string addressWithSpace = _address.address();
    std::copy_if(addressWithSpace.begin(),
                 addressWithSpace.end(),
                 std::back_inserter(addressWithoutSpaces),
                 [](auto sign){return !std::isspace(sign);});
    return Address(addressWithoutSpaces);
}
AddressProcessor AddressProcessor::removeSpaces()
{
    return areSpaces() ?
                AddressProcessor(removeSpacesOnOneString()) :
                AddressProcessor(_address.address());
}

bool AddressProcessor::isHTTPprefix() const
{
    return _address.https_mode()
            ? (_address.address().find("https://", 0, 7) == 0)
            : (_address.address().find("http://", 0, 7) == 0);
}

Address AddressProcessor::addHTTPPrefix()
{  
    return Address("http://" + _address.address());
}

Address AddressProcessor::getAddressWithHTTPprefix()
{
    return isHTTPprefix() ? Address(_address) : Address(addHTTPPrefix());
}
