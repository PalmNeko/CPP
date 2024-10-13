#include "Replace.hpp"
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

    infile.open(inFileName.c_str());
    if (!infile.good())
    {
        std::cout << "can't open: " << inFileName << std::endl;
        return (1);
    }
    outfile.open(outFileName.c_str());
    if (!outfile.good())
    {
        std::cout << "can't open: " << outFileName << std::endl;
        infile.close();
        return (1);
    }
    std::ostringstream oss;
    oss << infile.rdbuf();
    outfile << Replace::replace(oss.str(), argv[2], argv[3]);
    infile.close();
    outfile.close();
    return (0);
}
