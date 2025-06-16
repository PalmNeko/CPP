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
    mainchain.push_back((*first)->getLarger());
    while (sortIt != sortIte)
    {
        largechain.push_back((*sortIt)->getLarger());
        smallchain.push_back((*sortIt)->getSmaller());
        sortIt++;
    }
    if (leftovers != NULL)
        smallchain.push_back(leftovers);

    int sort_times = 1;
    while (mainchain.size() != smallchain.size() + largechain.size())
    {
        ++sort_times;
        insert<Container>(mainchain, smallchain, largechain, sort_times);
    }
    return mainchain;
}

template <typename Container>
void PmergeMe::insert(Container &mainchain, Container &smallchain, Container &largechain, int sort_times)
{
    typedef typename Container::iterator InputIterator;
    typedef std::reverse_iterator<InputIterator> ReverseIterator;

    size_t targetIndexBegin = ft::gen_sort_numbers(sort_times - 1);
    size_t targetIndexEnd = ft::gen_sort_numbers(sort_times);

    if (targetIndexBegin > smallchain.size() - 1)
        throw std::runtime_error("can't begin") ;

    InputIterator smallBegin = ft::next(smallchain.begin(), targetIndexBegin);
    InputIterator smallEnd = ft::next(smallchain.begin(), std::min(targetIndexEnd, smallchain.size()));
    ReverseIterator rSmallBegin(smallEnd);
    ReverseIterator rSmallEnd(smallBegin);

    InputIterator largeBegin = ft::next(largechain.begin(), targetIndexBegin);
    InputIterator largeEnd = ft::next(largechain.begin(), std::min(targetIndexEnd, largechain.size()));
    ReverseIterator rLargeBegin(largeEnd);
    ReverseIterator rLargeEnd(largeBegin);

    Container holdMainchain;
    Container largechainSequence;
    Container smallchainSequence;

    std::copy(largeBegin, largeEnd, std::back_insert_iterator<Container>(mainchain));
    largeBegin = ft::prev(largeBegin, 1);
    std::copy(largeBegin, largeEnd, std::back_insert_iterator<Container>(largechainSequence));
    std::copy(smallBegin, smallEnd, std::back_insert_iterator<Container>(smallchainSequence));

    while (smallchainSequence.size() != 0)
    {
        while (largechainSequence.size() != 0 && mainchain.back() != largechainSequence.back())
        {
            holdMainchain.push_back(mainchain.back());
            mainchain.pop_back();
        }
        if (largechainSequence.size() == smallchainSequence.size() + 1)
        {
            holdMainchain.push_back(mainchain.back());
            mainchain.pop_back();
            largechainSequence.pop_back();
        }
        Node &value = *smallchainSequence.back();
        InputIterator insertPos = ft::bsearch_for_insert(mainchain.begin(), mainchain.end(), value); // lowbound?
        mainchain.insert(insertPos, &value);
        smallchainSequence.pop_back();
    }
    while (holdMainchain.size() != 0)
    {
        mainchain.push_back(holdMainchain.back());
        holdMainchain.pop_back();
    }
}
