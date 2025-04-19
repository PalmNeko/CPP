#include <iostream>

bool getInput(const std::string& prompt, std::string& input)
{
    if (! std::cin)
        return (false);
    std::cout << prompt;
    std::getline(std::cin, input);
    if (input.empty())
        return (false);
    return (true);
}
