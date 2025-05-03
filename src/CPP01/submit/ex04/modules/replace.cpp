#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace ft
{
    std::string replace(const std::string &src, const std::string &find, const std::string &replace)
    {
        size_t foundPos;
        size_t nextSearchPos = 0;
        std::ostringstream oss;

        foundPos = src.find(find);
        if (find.size() != 0)
        {
            while (foundPos != std::string::npos)
            {
                oss.write(src.data() + nextSearchPos, foundPos - nextSearchPos);
                nextSearchPos = foundPos + find.size();
                oss << replace;
                foundPos = src.find(find, nextSearchPos);
            }
        }
        oss.write(src.data() + nextSearchPos, src.size() - nextSearchPos);
        return (oss.str());
    }
}
