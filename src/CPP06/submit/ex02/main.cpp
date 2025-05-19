#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "ex02.hpp"
#include <iostream>

template <class T> void testIdentify(void);

int main(void)
{
	std::cout << "== A ==" << std::endl;
	testIdentify<A>();
	std::cout << "== B ==" << std::endl;
	testIdentify<B>();
	std::cout << "== C ==" << std::endl;
	testIdentify<C>();
    for (int i = 0; i < 10; i++)
    {
        std::cout << "[" << i << "]" << std::endl;
        Base *ptr;
        ptr = generate();
        identify(ptr);
        identify(*ptr);
        delete ptr;
    }
    return (0);
}

template <class T> void testIdentify(void)
{
    Base *ptr;

    ptr = new T();
    identify(ptr);
    identify(*ptr);
    return;
}
