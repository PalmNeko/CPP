#include "PmergeMe.hpp"

template <typename Container, typename InputIterator>
Container PmergeMe::pmergeme(InputIterator first, InputIterator last)
{
    if (first == last)
        return Container();
    Node *leftovers;
    leftovers = NULL;

    Container pairs;
    pairs = create_pairs<Container, InputIterator>(first, last, &leftovers);

    Container sorted;
    sorted = pmergeme<Container, InputIterator>(pairs.begin(), pairs.end());

    Container mainchain = jacob_merge<Container, InputIterator>(sorted.begin(), sorted.end(), leftovers);

    ft::delete_range(pairs.begin(), pairs.end());
    return mainchain;
}

template <typename Container, typename InputIterator>
Container PmergeMe::create_pairs(InputIterator first, InputIterator last, Node **leftovers)
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

template <typename Container, typename InputIterator>
Container PmergeMe::jacob_merge(InputIterator first, InputIterator last, Node *leftovers)
{
    Container mainchain;
    Container largechain;
    Container smallchain;

    InputIterator sortIt;
    InputIterator sortIte;

    if (std::distance(first, last) == 0)
    {
        if (leftovers)
            mainchain.push_back(leftovers);
        return mainchain;
    }
    sortIt = first;
    sortIte = last;

    mainchain.push_back((*first)->getSmaller());
    while (sortIt != sortIte)
    {
        mainchain.push_back((*sortIt)->getLarger());
        largechain.push_back((*sortIt)->getLarger());
        smallchain.push_back((*sortIt)->getSmaller());
        sortIt++;
    }
    if (leftovers != NULL)
        smallchain.push_back(leftovers);

    std::stack<Node *, Container> holdStack;
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
            InputIterator pos
                = ft::bsearch_for_insert(mainchain.begin(), mainchain.end(), **smallchainIt);
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
