#ifndef UTILS_H
#define UTILS_H

#include <cstddef>

namespace ft
{
    template <typename InputIterator> void delete_range(InputIterator first, InputIterator last);
    template <typename InputIterator>
    void print(InputIterator first, InputIterator last, bool colored = false);
    template <typename InputIterator> InputIterator at(InputIterator it, size_t now, size_t at);
    template <typename InputIterator> InputIterator next(InputIterator it, size_t index);
    template <typename InputIterator, typename T>
    InputIterator bsearch_for_insert(InputIterator first, InputIterator last, T &value);
    size_t gen_sort_numbers(size_t no);
} // namespace ft

#include "utils.tpp"

#endif // UTILS_H
