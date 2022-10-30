#include <string>
#include <boost/algorithm/string.hpp>

namespace func
{
    std::string getName(std::string &input)
    {
        auto name = "Marcello";
        return name + boost::to_upper_copy(input);
    }
}
