#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char *argv[])
{
	(void)argc;
	argv++;
	int argNum = 1;
    while (*argv != NULL)
    {
		if (argc >= 3)
			std::cout << "arg[" << argNum << "]: " << *argv << std::endl;
        ScalarConverter::convert(std::string(*argv));
		argNum += 1;
        argv++;
    }
	return (0);
}
// ./a.out 0 42 256 f nanf +inff +inf nan a 2147483648 -2147483648
