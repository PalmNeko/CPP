#ifndef ITER__HPP
# define ITER__HPP

#include <cstddef>

template <typename T, typename F>
	void iter(T *array, size_t len, F callbackFn)
	{
		for (size_t i = 0; i < len; i++)
			callbackFn(array[i]);
		return ;
	}

#endif // ITER__HPP
