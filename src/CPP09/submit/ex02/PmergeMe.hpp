#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include "Node.hpp"

#include <iostream>
#include <vector>

class PmergeMe
{
    private:
        typedef std::vector<Node *>::iterator InputIterator;
        typedef std::vector<Node *> Container;

    protected:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        virtual ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &rhs);

    public:
        static Container pmergeme(InputIterator first, InputIterator last);
        static void print(InputIterator first, InputIterator last);
        static Container create_pairs(InputIterator first, InputIterator last, Node **leftovers);
        static void destroy_pairs(InputIterator first, InputIterator end);
};

#endif // PMERGE_ME_HPP
