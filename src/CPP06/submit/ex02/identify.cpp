#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <string>
#include <iostream>

void identify(Base *p)
{
	std::string casted_type;
	Base *casted_p = NULL;

	casted_p = dynamic_cast<A *>(p);
	if (casted_p != NULL)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	casted_p = dynamic_cast<B *>(p);
	if (casted_p != NULL)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	casted_p = dynamic_cast<C *>(p);
	if (casted_p != NULL)
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

void identify(Base &p)
{
	try {
		Base &casted_p = dynamic_cast<A &>(p);
		(void)casted_p;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception&e)
	{}

	try {
		Base &casted_p = dynamic_cast<B &>(p);
		(void)casted_p;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception&e)
	{}

	try {
		Base &casted_p = dynamic_cast<C &>(p);
		(void)casted_p;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::exception&e)
	{}


}
