
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <iostream>

void testMateria(AMateria *m);

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	// test ice
	{
		AMateria *ice;
		ice = new Ice();
		testMateria(ice);
		delete ice;
	}
	// test cure
	{
		AMateria *cure;
		cure = new Cure();
		testMateria(cure);
		delete cure;
	}
	// test materia source and character
	{
		IMateriaSource* src = new MateriaSource();
		try {
			src->learnMateria(new Ice());
			src->learnMateria(new Ice());
			src->learnMateria(new Cure());
			src->learnMateria(new Ice());
			src->learnMateria(new Ice()); // over learn

			{
				AMateria *ice;
				ice = src->createMateria("ice");
				testMateria(ice);
				delete ice;
			}
			{
				AMateria *cure;
				cure = src->createMateria("cure");
				testMateria(cure);
				delete cure;
			}
			// test character
			Character* bob = new Character("bob");
			try {
				bob->equip(src->createMateria("ice"));
				bob->equip(src->createMateria("cure"));
				bob->equip(src->createMateria("cure"));
				bob->equip(src->createMateria("cure"));
				AMateria* tmp;
				tmp = src->createMateria("cure");
				bob->equip(tmp); // over equip
				delete tmp;

				Character target("Alice");
				std::cout << bob->getName() << ": ";
				bob->use(0, target);
				bob->use(2, target);
				bob->use(-1, target); // out of range idx
				bob->use(15, target);
			}
			catch (const std::exception& e)
			{
				delete bob;
				throw ;
			}
			Character copied;
			copied = *bob; // deep copy
			delete bob;
			AMateria *tmp;
			tmp = copied.pickMateria(0);
			copied.unequip(0);
			delete tmp; // unequip not delete check
			Character target("Alice");
			copied.use(0, target);
		}
		catch (const std::exception& e)
		{}
		delete src;
	}
	return 0;
}

void testMateria(AMateria *m)
{
	std::cout << m->getType() << " : ";
	Character bob("Bob");
	m->use(bob);

	AMateria *cloned = m->clone();
	std::cout << cloned->getType() << " : ";
	Character alice("Alice");
	cloned->use(alice);
	delete cloned;
}
