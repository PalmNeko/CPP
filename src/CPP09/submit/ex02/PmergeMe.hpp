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
        // typedef typename ContainerClass::iterator InputIterator;
        // typedef ContainerClass Container;
        // typedef std::stack<Node *, ContainerClass> Stack;

    protected:
    public:
        PmergeMe() {}

        PmergeMe(const PmergeMe &other)
        {
            *this = other;
        }

        ~PmergeMe() {}

        PmergeMe &operator=(const PmergeMe &rhs)
        {
            if (this != &rhs)
            {
            }
            return *this;
        }
        template <typename Container, typename InputIterator>
        Container pmergeme(InputIterator first, InputIterator last);
        template <typename Container, typename InputIterator>
        Container create_pairs(InputIterator first, InputIterator last, Node **leftovers);
        template <typename Container, typename InputIterator>
        Container jacob_merge(Container &sorted_pairs, Node *leftovers);
};

#include "PmergeMe.tpp"

#endif // PMERGE_ME_HPP
