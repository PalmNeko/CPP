#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include "Node.hpp"
#include "utils.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <limits>
#include <cmath>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &rhs);

        template <typename Container, typename InputIterator>
        Container pmergeme(InputIterator first, InputIterator last);

        template <typename Container, typename InputIterator>
        Container create_pairs(InputIterator first, InputIterator last, Node **leftovers);

        template <typename Container, typename InputIterator>
        Container jacob_merge(InputIterator first, InputIterator last, Node *leftovers);
};

#include "PmergeMe.tpp"

#endif // PMERGE_ME_HPP
