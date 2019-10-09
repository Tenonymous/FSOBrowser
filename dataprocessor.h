#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <address.h>
#include <vector>
#include <fstream>
#include <map>
class DataProcessor
{
private:
    std::ifstream historyFile;
    std::string nameOfHistoryFile;
    std::ifstream settingsFile;
    std::string nameOfSettingsFile;

    std::vector<Address> readHistory();
    std::vector<Address> orderHistory();
public:
    DataProcessor() : historyFile(), nameOfHistoryFile(), nameOfSettingsFile() {}
    DataProcessor(std::string _nameOfHistoryFile, std::string _nameOfSettingsFile)
        : historyFile(_nameOfHistoryFile),
          nameOfHistoryFile(_nameOfHistoryFile),
          settingsFile(_nameOfSettingsFile),
          nameOfSettingsFile(_nameOfSettingsFile)
    {}

    std::vector<Address> getAddressesList();
    void writeAddressList(const std::vector<Address>&) const;
    void saveSettings(const std::map<std::string, int>&) const;
    std::map<std::string, int> loadSetings();
};

#endif // DATAPROCESSOR_H
