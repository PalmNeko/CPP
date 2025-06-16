#include "utils.hpp"

template <typename InputIterator>
void ft::delete_range(InputIterator first, InputIterator last)
{
    while (first != last)
    {
        delete *first;
        first++;
    }
}
