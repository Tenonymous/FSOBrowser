#include "engine.h"
#include "addressprocessor.h"
Engine::Engine()
{

}

std::string Engine::processAddress(const std::string & rawAddress)
{
    return AddressProcessor
           (AddressProcessor(rawAddress).removeSpaces())
                                       .getAddressWithHTTPprefix();
}

