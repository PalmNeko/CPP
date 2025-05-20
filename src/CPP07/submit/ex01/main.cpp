#include "iter.hpp"
#include <iostream>

template <typename T> void outValue(T &value);
template <typename T> void square(T &value);

int main(void)
{
    int values[] = {1, 1, 2, 3, 5, 8, 13};
	const size_t len = sizeof(values) / sizeof(values[0]);

    iter(values, len, outValue);
    iter(values, len, square);
    iter(values, len, outValue);
    return (0);
}

template <typename T> void outValue(T &value)
{
    std::cout << value << std::endl;
}

template <typename T> void square(T &value)
{
	value *= value;
}
