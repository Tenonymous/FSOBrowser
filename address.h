#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
private:
    constexpr static auto minimumAddressLength = 11;
    std::string _address;
    bool _https_mode;
    unsigned long getIndexToEndOfPrefix(const std::string&) const;
public:
    Address();
    Address(const std::string&);
    Address(const Address&) = default;
    Address& operator=(const Address&) = default;

    Address& operator=(const std::string&);
    Address(Address&&) = default;
    Address& operator=(Address&&) = default;

    ~Address() = default;

    operator std::string() const
    {
        return _address;
    }

    std::string getPrefix() const;
    std::string getAddressWithoutPrefix() const;
    std::string address() const{ return _address;}
    bool https_mode() const { return _https_mode;}
    bool isIncorrect() const;
};

inline bool operator<(const Address& left, const Address& right)
{
    return left.getAddressWithoutPrefix() < right.getAddressWithoutPrefix();
}

inline bool operator>(const Address& left, const Address& right)
{
    return right < left;
}

inline bool operator==(const Address& left, const Address& right)
{
    return left.getAddressWithoutPrefix() == right.getAddressWithoutPrefix();
}

inline bool operator==(const Address& left, const std::string& right)
{
    return left == Address(right);
}

inline bool operator==(const std::string& left, Address right)
{
    return right == left;
}

inline bool operator!=(const Address& left, const Address& right)
{
    return !(left == right);
}



#endif // ADDRESS_H
