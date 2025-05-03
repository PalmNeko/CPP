#include "ft.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

// {{REPLACE_STRING}}
int main(int argc, char *argv[])
{
    if (argc != 4)
        return (0);
    std::ifstream infile;
    std::ofstream outfile;
    std::string inFileName(argv[1]);
    std::string outFileName(std::string(argv[1]) + ".replace");

    try
    {
        infile.open(inFileName.c_str());
        if (!infile.good())
            throw std::runtime_error("can't open: " + inFileName);
        outfile.open(outFileName.c_str());
        if (!outfile.good())
            throw std::runtime_error("can't open: " + outFileName);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }
    std::ostringstream oss;
    oss << infile.rdbuf();
    outfile << ft::replace(oss.str(), argv[2], argv[3]);
    return (0);
}
