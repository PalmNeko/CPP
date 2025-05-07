#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
    *this = materiaSource;
}

MateriaSource::~MateriaSource(void)
{}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiaSource)
{
    if (this != &materiaSource)
    {
    }
    return *this;
}
