#include "Brain.hpp"
#include <stdexcept>
#include <stdlib.h>
#include <iostream>

Brain::Brain(void)
{
    this->setRandomIdea();
    std::cout << " + Brain" << std::endl;
}

Brain::Brain(const Brain& brain)
{
    *this = brain;
    std::cout << " @ Copy(Brain)" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << " - Brain" << std::endl;
}

Brain& Brain::operator=(const Brain& brain)
{
    if (this != &brain)
    {
        for (size_t i = 0; i < Brain::ideasSize; i++)
            this->ideas[i] = brain.ideas[i];
    }
    std::cout << " = Brain" << std::endl;
    return *this;
}

void Brain::setRandomIdea(void)
{
    const std::string randomIdeas[] = {
        "I'm cat",
        "You're cat",
        "Maybe cat",
        "I'm dog",
        "You're dog",
        "Maybe dog",
    };
    const size_t randomSize = sizeof(randomIdeas) / sizeof(randomIdeas[0]);
    for (size_t i = 0; i < Brain::ideasSize; i++)
        this->ideas[i] = randomIdeas[(rand() % randomSize)];
}

std::string Brain::getIdea(size_t index) const
{
    if (index > Brain::ideasSize - 1)
        throw std::range_error("out of range: idea index");
    return this->ideas[index];
}
