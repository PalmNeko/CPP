#ifndef UTILS_H
# define UTILS_H

namespace ft
{
    template <typename InputIterator> void delete_range(InputIterator first, InputIterator last);
    template <typename InputIterator> void print(InputIterator first, InputIterator last);
}

#include "utils.tpp"

#endif // UTILS_H
