#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include "Node.hpp"

#include <iostream>
#include <vector>
#include <stack>

class PmergeMe
{
    public:
        typedef std::vector<Node *>::iterator InputIterator;
        typedef std::vector<Node *> Container;
        typedef std::stack<Node *, std::vector<Node *> > Stack;

    protected:

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        virtual ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &rhs);

        Container pmergeme(InputIterator first, InputIterator last);
        void print(InputIterator first, InputIterator last, bool colored = false);
        Container create_pairs(InputIterator first, InputIterator last, Node **leftovers);
        size_t gen_sort_numbers(size_t no);
        InputIterator at(InputIterator it, size_t now, size_t at);
        InputIterator next(InputIterator it, size_t index);
        void binary_insert(Container &container, Node *value);
        Container jacob_merge(Container &sorted_pairs, Node *leftovers);
        InputIterator binary_insert_iterator(InputIterator first, InputIterator last, const Node &value);
        void destroy_pairs(InputIterator first, InputIterator end);
};

#endif // PMERGE_ME_HPP
