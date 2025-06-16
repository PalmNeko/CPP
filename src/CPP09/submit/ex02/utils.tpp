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


template <typename InputIterator> void ft::print(InputIterator first, InputIterator last)
{
    InputIterator res;

    res = first;
    while (first != last)
    {
        std::cout << *first;
        ++first;
        if (first != last)
            std::cout << " ";
    }
    std::cout << std::endl;
}
