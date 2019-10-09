#include "dataprocessor.h"
#include <iterator>

std::vector<Address> DataProcessor::readData()
{
    std::vector<Address> addresses;
    std::copy(std::istream_iterator<std::string>(file),
              std::istream_iterator<std::string>{},
              std::back_inserter(addresses));
    return addresses;
}

std::vector<Address> DataProcessor::orderData()
{
    auto addresses = readData();
    std::sort(std::begin(addresses), std::end(addresses));
    return addresses;
}

std::vector<Address> DataProcessor::getAddressesList()
{
    auto addresses = orderData();
    addresses.erase(std::unique(std::begin(addresses),
                                std::end(addresses)),
                    std::end(addresses));
    return addresses;
}



void DataProcessor::writeAddressList(const std::vector<Address> & addressesList) const
{
   /* std::vector<std::string> addresses(addressesList.size());
    std::transform(addressesList.begin(), addressesList.end(), addresses.begin(), [](Address addr){
        return addr.address();
    });
    writeAddressList(addresses);*/
    std::ofstream of(filename);
    std::copy(std::begin(addressesList),
              std::end(addressesList),
              std::ostream_iterator<std::string>(of, "\n"));
}

