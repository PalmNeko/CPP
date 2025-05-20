#ifndef ITER__HPP
# define ITER__HPP

#include <cstddef>

template <typename T>
	void iter(T *array, size_t len, void (*callbackFn)(T&))
	{
		for (size_t i = 0; i < len; i++)
			callbackFn(array[i]);
		return ;
	}

#endif // ITER__HPP
