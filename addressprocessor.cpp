#include "addressprocessor.h"
#include "algorithm"
AddressProcessor::AddressProcessor()
{

}

bool AddressProcessor::areSpaces()
{
    return address.find(' ') != std::string::npos;
}
std::string AddressProcessor::removeSpacesOnOneString(std::string& rawaddress)
{
    rawaddress.erase(std::remove_if(rawaddress.begin(), rawaddress.end(),
                                    [](auto sign){return std::isspace(sign);}), rawaddress.end());
    return  rawaddress;
}
std::string AddressProcessor::removeSpaces()
{
    auto copyOfAddress = address;
    return areSpaces() ? removeSpacesOnOneString(copyOfAddress) : address;
}

bool AddressProcessor::isHTTPprefix()
{
    return address.find("http://", 0, 7) == 0;
}

std::string AddressProcessor::addHTTPPrefix(std::string & nonHTTPAddress)
{
    nonHTTPAddress.insert(0, "http://");
    return nonHTTPAddress;
}

std::string AddressProcessor::getAddressWithHTTPprefix()
{
    auto copyOfAddress = address;
    return isHTTPprefix() ? address : addHTTPPrefix(copyOfAddress);
}
