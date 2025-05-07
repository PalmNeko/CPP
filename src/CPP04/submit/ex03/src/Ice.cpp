#include "Ice.hpp"
#include <iostream>

Ice::Ice(void)
    : AMateria("ice")
{}

Ice::Ice(const Ice& ice)
{
    *this = ice;
}

Ice::~Ice(void)
{}

Ice& Ice::operator=(const Ice& ice)
{
    if (this != &ice)
    {
        this->AMateria::operator=(ice);
    }
    return *this;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " + target.getName() + " *" << std::endl;
}

Ice* Ice::clone(void) const
{
    return (new Ice(*this));
}
