#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data value = {
		.age = 10
	};

	std::cout << "value.age: " << value.age << std::endl;
	uintptr_t uintptr = Serializer::serialize(&value);
	Data *data_p = Serializer::deserialize(uintptr);
	std::cout << "value.age: " << data_p->age << std::endl;
	return (0);
}
