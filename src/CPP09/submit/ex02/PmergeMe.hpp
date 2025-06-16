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

template <typename ContainerClass> class PmergeMe
{
    public:
        typedef typename ContainerClass::iterator InputIterator;
        typedef ContainerClass Container;
        typedef std::stack<Node *, ContainerClass> Stack;

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

        Container pmergeme(InputIterator first, InputIterator last)
        {
            if (first == last)
                return Container();
            Node *leftovers;
            leftovers = NULL;

            Container pairs;
            pairs = create_pairs(first, last, &leftovers);

            Container sorted;
            sorted = pmergeme(pairs.begin(), pairs.end());

            Container mainchain = jacob_merge(sorted, leftovers);

            ft::delete_range(pairs.begin(), pairs.end());
            return mainchain;
        }

        Container create_pairs(InputIterator first,
                                                   InputIterator last,
                                                   Node **leftovers)
        {
            Container pairs;
            InputIterator it;
            InputIterator ite;
            size_t index;
            Node *a;
            Node *b;

            *leftovers = NULL;
            it = first;
            ite = last;
            index = 0;
            while (it != ite)
            {
                if (index % 2 == 0)
                    a = *it;
                else
                {
                    b = *it;
                    try
                    {
                        Node *newNode = Node::create(a, b);
                        pairs.push_back(newNode);
                    }
                    catch (const std::exception &e)
                    {
                        ft::delete_range(pairs.begin(), pairs.end());
                        throw;
                    }
                }
                it++;
                index++;
            }
            if (index % 2 == 1)
                *leftovers = a;
            return pairs;
        }

        Container jacob_merge(Container &sorted_pairs,
                                                  Node *leftovers)
        {
            Container mainchain;
            Container largechain;
            Container smallchain;

            InputIterator sortIt;
            InputIterator sortIte;

            if (sorted_pairs.size() == 0)
            {
                if (leftovers)
                    mainchain.push_back(leftovers);
                return mainchain;
            }
            sortIt = sorted_pairs.begin();
            sortIte = sorted_pairs.end();

            mainchain.push_back(sorted_pairs.front()->getSmaller());
            while (sortIt != sortIte)
            {
                mainchain.push_back((*sortIt)->getLarger());
                largechain.push_back((*sortIt)->getLarger());
                smallchain.push_back((*sortIt)->getSmaller());
                sortIt++;
            }
            if (leftovers != NULL)
                smallchain.push_back(leftovers);

            Stack holdStack;
            int sort_times = 1;

            size_t sortIndex;
            InputIterator largechainIt;
            InputIterator smallchainIt;

            sortIndex = 0;
            while (sortIndex != smallchain.size() - 1)
            {
                size_t smallIndex;
                size_t largeIndex;

                sort_times++;
                sortIndex = std::min(ft::gen_sort_numbers(sort_times) - 1,
                                     smallchain.size() - 1); // 2 -> 3
                smallIndex = sortIndex;

                InputIterator smallchainIte;
                smallchainIt = ft::next(smallchain.begin(), smallIndex);
                smallchainIte = ft::next(smallchain.begin(), ft::gen_sort_numbers(sort_times - 1) - 1);
                largeIndex = std::min(smallIndex, largechain.size() - 1);
                largechainIt = ft::next(largechain.begin(), largeIndex);
                if (holdStack.size() != 0)
                {
                    while (mainchain.back() != (*largechainIt))
                    {
                        mainchain.push_back(holdStack.top());
                        holdStack.pop();
                    }
                }
                while (smallchainIt != smallchainIte)
                {

                    while (mainchain.back() != (*largechainIt))
                    {
                        holdStack.push(mainchain.back());
                        mainchain.pop_back();
                    }
                    if (smallIndex == largeIndex)
                    {
                        holdStack.push(mainchain.back());
                        mainchain.pop_back();
                    }
                    InputIterator pos = ft::bsearch_for_insert(mainchain.begin(), mainchain.end(), **smallchainIt);
                    mainchain.insert(pos, *smallchainIt);
                    smallchainIt--;
                    smallIndex--;
                    largeIndex = std::min(smallIndex, largechain.size() - 1);
                    largechainIt = ft::next(largechain.begin(), largeIndex);
                }
            }
            while (holdStack.size() != 0)
            {
                mainchain.push_back(holdStack.top());
                holdStack.pop();
            }
            return mainchain;
        }
};

#endif // PMERGE_ME_HPP
