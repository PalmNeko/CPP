#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	static bool isInitalized;

	if (isInitalized == false)
	{
		std::srand(time(NULL));
		isInitalized = true;
	}
	int rand = std::rand();
	int selector = rand % 3;
	if (selector == 0)
		return new A();
	else if (selector == 1)
		return new B();
	else
		return new C();
}
