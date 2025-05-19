#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
	// copy constructor
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	if (this != &rhs) {
		// assignment logic
	}
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	void *void_p = reinterpret_cast<void *>(ptr);
	return reinterpret_cast<uintptr_t>(void_p);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	void *void_p = reinterpret_cast<void *>(raw);
	return reinterpret_cast<Data *>(void_p);
}
