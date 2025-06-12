#include "RPN.hpp"

#include <iostream>
#include <stdexcept>

int _main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    try
    {
        _main(argc, argv);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Error" << std::endl;
    }
    return 0;
}

int _main(int argc, char *argv[])
{
    if (argc != 2)
        return 0;
    std::cout << RPN::rpn(argv[1]) << std::endl;
    return 0;
}
