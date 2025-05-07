#include "Cure.hpp"
#include <iostream>

Cure::Cure(void)
    : AMateria("cure")
{}

Cure::Cure(const Cure& cure)
    : AMateria(cure)
{
    *this = cure;
}

Cure::~Cure(void)
{}

Cure& Cure::operator=(const Cure& cure)
{
    if (this != &cure)
    {
        this->AMateria::operator=(cure);
    }
    return *this;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " + target.getName() + "’s wounds *" << std::endl;
}

Cure* Cure::clone(void) const
{
    return (new(std::nothrow) Cure(*this));
}
