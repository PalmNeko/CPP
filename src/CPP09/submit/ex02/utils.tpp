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

template <typename InputIterator, typename T>
InputIterator ft::bsearch_for_insert(InputIterator first,
                                     InputIterator last,
                                     T &value)
{
    if (std::distance(first, last) == 0)
        return first;
    size_t low = 0;
    size_t mid;
    size_t high = std::distance(first, last);

    InputIterator midIt;

    while (low < high)
    {
        mid = (low + high) / 2;
        midIt = first;
        std::advance(midIt, mid);
        if (value < *midIt)
            high = mid;
        else
            low = mid + 1;
    }
    midIt = first;
    std::advance(midIt, low);
    return midIt;
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
