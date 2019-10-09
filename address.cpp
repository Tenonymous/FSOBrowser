#include "address.h"

Address::Address()
{

}

Address::Address(const std::string& address)
{
    _address = address;
    _https_mode = _address.find("https://") != std::string::npos
                  && _address.find("https://") == 0;
}


Address& Address::operator=(const std::string& straddr)
{
    this->_address = straddr;
    this->_https_mode = _address.find("https") != std::string::npos
                        && _address.find("https://") == 0;
    return *this;
}


unsigned long Address::getIndexToEndOfPrefix(const std::string& pref) const
{
    auto indexOfPrefix = _address.find(pref + "www") != std::string::npos
                        ? _address.find_first_not_of(pref + "www")
                        : _address.find(pref) != std::string::npos
                            ? _address.find_first_not_of(pref)
                            : std::string::npos;
    return indexOfPrefix;
}

std::string Address::getPrefix() const
{
    auto indexOfPrefix = _https_mode
                         ? getIndexToEndOfPrefix("https://")
                         : getIndexToEndOfPrefix("http://");

    return indexOfPrefix != std::string::npos ? _address.substr(0, indexOfPrefix)
                                              : std::string{};

}

std::string Address::getAddressWithoutPrefix() const
{

    return _address.find("www") != std::string::npos
                ? _address.substr(getPrefix().size() + 1)
                : _address.substr(getPrefix().size());
}

bool Address::isIncorrect() const
{
    return _address.find('.') == std::string::npos
           && _address.size() < minimumAddressLength;
}

