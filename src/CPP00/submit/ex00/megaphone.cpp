#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::string	joined = "";
	for (int i = 0; i < argc - 1; i++)
		joined.append(argv[i + 1]);
	for (std::string::size_type i = 0; i < joined.size(); i++)
	{
		if (std::islower(joined[i]))
			joined[i] = 'A' + (joined[i] - 'a');
	}
	std::cout << joined << std::endl;
	return (0);
}
