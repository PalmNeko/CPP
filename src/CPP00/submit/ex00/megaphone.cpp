#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::ostringstream oss;
	for (int i = 1; i < argc; i++)
		oss << argv[i];
	std::string joined = oss.str();
	for (std::string::iterator it = joined.begin(); it < joined.end(); it++)
		*it = std::toupper(*it);
	std::cout << joined << std::endl;
	return (0);
}
