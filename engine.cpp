#include "engine.h"
#include "stringprocessor.h"
Engine::Engine()
{

}

std::string Engine::processAddress(const std::string & rawAddress)
{
    return StringProcessor
           (StringProcessor(rawAddress).removeSpaces())
                                       .getAddressWithHTTPprefix();
}

