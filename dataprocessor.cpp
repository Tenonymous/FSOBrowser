#include "dataprocessor.h"
#include <iterator>
#include <tuple>
#include <sstream>

std::vector<Address> DataProcessor::readHistory()
{
    std::vector<Address> addresses;
    std::copy(std::istream_iterator<std::string>(historyFile),
              std::istream_iterator<std::string>{},
              std::back_inserter(addresses));
    return addresses;
}

std::vector<Address> DataProcessor::orderHistory()
{
    auto addresses = readHistory();
    std::sort(std::begin(addresses), std::end(addresses));
    return addresses;
}

std::vector<Address> DataProcessor::getAddressesList()
{
    auto addresses = orderHistory();
    addresses.erase(std::unique(std::begin(addresses),
                                std::end(addresses)),
                    std::end(addresses));
    return addresses;
}



void DataProcessor::writeAddressList(const std::vector<Address> & addressesList) const
{
    std::ofstream of(nameOfHistoryFile);
    std::copy_if(std::begin(addressesList),
              std::end(addressesList),
              std::ostream_iterator<std::string>(of, "\n"),
              [](auto address){
                return !address.isIncorrect();
               });
}

void DataProcessor::saveSettings(const std::map<std::string, int>& settings) const
{
    std::ofstream of(nameOfSettingsFile);
    std::transform(std::begin(settings),
                   std::end(settings),
                   std::ostream_iterator<std::string>(of, "\n"),
                   [](std::pair<std::string, int> paramPair){
                        return paramPair.first + ":" + std::to_string(paramPair.second);
                   });
}

std::map<std::string, int> DataProcessor::loadSetings()
{
    std::map<std::string, int> settings;
    std::string stringsSettings;
    while(std::getline(settingsFile, stringsSettings)) {
        auto paramName = stringsSettings.substr(0,stringsSettings.find(":"));
        std::istringstream ss(stringsSettings.substr(stringsSettings.find(":") + 1));
        int paramValue;
        ss >> paramValue;
        settings.insert({paramName,paramValue});
    }

    return settings;
}
