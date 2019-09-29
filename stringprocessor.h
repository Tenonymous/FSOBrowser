#ifndef STRINGPROCESSOR_H
#define STRINGPROCESSOR_H
#include "string"
class StringProcessor
{
private:
    std::string str;

    std::string removeSpacesOnOneString(std::string&);
    std::string addHTTPPrefix(std::string&);
public:
    StringProcessor();
    StringProcessor(const std::string& _str) : str(_str){}
    bool areSpaces();
    std::string removeSpaces();
    bool HTTPprefixExist();
    std::string getAddressWithHTTPprefix();


};

#endif // STRINGPROCESSOR_H
