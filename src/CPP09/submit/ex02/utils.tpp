#include "utils.hpp"
#include <iostream>

template <typename InputIterator>
void ft::delete_range(InputIterator first, InputIterator last)
{
    while (first != last)
    {
        delete *first;
        first++;
    }
}

template <typename InputIterator> InputIterator ft::at(InputIterator it, size_t now, size_t at)
{
    std::advance(it, at - now);
    return it;
}

template <typename InputIterator> InputIterator ft::next(InputIterator it, size_t index)
{
    std::advance(it, index);
    return it;
}

template <typename InputIterator> InputIterator ft::prev(InputIterator it, size_t index)
{
    std::advance(it, -index);
    return it;
}

template <typename InputIterator>
void ft::print(InputIterator first, InputIterator last, bool colored)
{
    InputIterator it;
    InputIterator ite;
    it = first;
    ite = last;
    int i = 0;
    while (it != ite)
    {
        if (i % 2 == 0 && colored)
        {
            if (i % 4 == 0)
                std::cout << "\e[32m";
            else
                std::cout << "\e[34m";
        }
        i++;
        std::cout << *it << " ";
        it++;
    }
    if (colored)
        std::cout << "\e[m";

    std::cout << std::endl;
}
