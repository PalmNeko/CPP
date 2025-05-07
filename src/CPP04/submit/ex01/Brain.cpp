#include "Brain.hpp"
#include <stdexcept>

const size_t Brain::ideasSize = 100;

Brain::Brain(void)
{}

Brain::Brain(const Brain& brain)
{
    *this = brain;
}

Brain::~Brain(void)
{}

Brain& Brain::operator=(const Brain& brain)
{
    if (this != &brain)
    {
        for (size_t i = 0; i < Brain::ideasSize; i++)
            this->ideas[i] = brain.ideas[i];
    }
    return *this;
}

void Brain::setIdea(size_t index, const std::string& idea)
{
    if (index > Brain::ideasSize - 1)
        return ;
    this->ideas[index] = idea;
}

std::string Brain::getIdea(size_t index) const
{
    if (index > Brain::ideasSize - 1)
        throw std::range_error("out of range: idea index");
    return this->ideas[index];
}
