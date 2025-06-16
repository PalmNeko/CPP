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
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        virtual ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &rhs);

    public:
        static Container pmergeme(InputIterator first, InputIterator last);
        static void print(InputIterator first, InputIterator last);
        static Container create_pairs(InputIterator first, InputIterator last, Node **leftovers);
        static size_t calc_index(size_t no);
        static InputIterator at(InputIterator it, size_t now, size_t at);
        static InputIterator next(InputIterator it, size_t index);
        static void binary_insert(Container &container, Node *value);
        static Container jacob_merge2(Container &sorted_pairs, Node *leftovers);
        static InputIterator binary_insert_iterator(InputIterator first, InputIterator last, const Node &value);
        static void destroy_pairs(InputIterator first, InputIterator end);
};

#endif // PMERGE_ME_HPP
