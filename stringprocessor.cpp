#include "stringprocessor.h"
#include "algorithm"
StringProcessor::StringProcessor()
{

}

bool StringProcessor::areSpaces()
{
    return str.find(' ') != std::string::npos;
}
std::string StringProcessor::removeSpacesOnOneString(std::string& copyString)
{
    copyString.erase(std::remove_if(copyString.begin(), copyString.end(),
                                    [](auto sign){return std::isspace(sign);}), copyString.end());
    return  copyString;
}
std::string StringProcessor::removeSpaces()
{
    auto copyString = str;
    return areSpaces() ? removeSpacesOnOneString(copyString) : str;
}

bool StringProcessor::HTTPprefixExist()
{
    return str.find("http://", 0, 7) == 0;
}

std::string StringProcessor::addHTTPPrefix(std::string & copyString)
{
    copyString.insert(0, "http://");
    return copyString;
}

std::string StringProcessor::getAddressWithHTTPprefix()
{
    auto copyString = str;
    return HTTPprefixExist() ? str : addHTTPPrefix(copyString);
}
