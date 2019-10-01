#include "dataprocessor.h"
#include <iterator>

std::vector<std::string> DataProcessor::getAddressesList()
{
    std::vector<std::string> vec;
    std::copy(std::istream_iterator<std::string>(file),
              std::istream_iterator<std::string>{},
              std::back_inserter(vec));
    return vec;
}
