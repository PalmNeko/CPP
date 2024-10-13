#include "Replace.hpp"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

std::string Replace::replace(const std::string& src, const std::string& find, const std::string& replace)
{
    size_t found;
    size_t nextSearchPos = 0;
    std::ostringstream oss;

    found = src.find(find);
    if (find.size() != 0)
    {
        while (found != std::string::npos)
        {
            oss.write(src.data() + nextSearchPos, found - nextSearchPos);
            nextSearchPos = found + find.size();
            oss << replace;
            found = src.find(find, nextSearchPos);
        }
    }
    oss.write(src.data() + nextSearchPos, src.size() - nextSearchPos);
    return (oss.str());
}
