#include "AMateria.hpp"

AMateria::AMateria(void)
{}

AMateria::AMateria(const AMateria& aMateria)
{
    *this = aMateria;
}

AMateria::~AMateria(void)
{}

AMateria& AMateria::operator=(const AMateria& aMateria)
{
    if (this != &aMateria)
    {
        this->type = aMateria.type;
    }
    return *this;
}

AMateria::AMateria(std::string const & type)
    : type(type)
{}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter&)
{}
