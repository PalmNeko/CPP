#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{}

ICharacter::ICharacter(const ICharacter&)
{}

ICharacter::~ICharacter(void)
{}

ICharacter& ICharacter::operator=(const ICharacter& iCharacter)
{
	if (this == &iCharacter)
	{
	}
	return *this;
}
