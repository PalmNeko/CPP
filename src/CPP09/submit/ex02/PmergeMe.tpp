#include "PmergeMe.hpp"
#include <functional>

template <typename Container, typename InputIterator>
Container PmergeMe::pmergeme(InputIterator first, InputIterator last)
{
    if (first == last)
        return Container();

    Container pairs;
    Container sorted;
    Container mainchain;
    Node *leftovers;

    leftovers = NULL;
    pairs = create_pairs<Container, InputIterator>(first, last, &leftovers);
    try
    {
        sorted = pmergeme<Container, InputIterator>(pairs.begin(), pairs.end());
        mainchain = jacob_merge<Container, InputIterator>(sorted.begin(), sorted.end(), leftovers);
    }
    catch (const std::exception &e)
    {
        ft::delete_range(pairs.begin(), pairs.end());
        throw ;
    }
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

    if (std::distance(first, last) == 0)
    {
        if (leftovers)
            mainchain.push_back(leftovers);
        return mainchain;
    }

    mainchain.push_back((*first)->getSmaller());
    mainchain.push_back((*first)->getLarger());
    std::transform(first, last, std::back_inserter(largechain), std::mem_fun(static_cast<Node* (Node::*)()>(&Node::getLarger)));
    std::transform(first, last, std::back_inserter(smallchain), std::mem_fun(static_cast<Node* (Node::*)()>(&Node::getSmaller)));
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

    size_t targetIndexBegin = ft::gen_sort_numbers(sort_times - 1);
    size_t targetIndexEnd = ft::gen_sort_numbers(sort_times);

    if (targetIndexBegin > smallchain.size() - 1)
        throw std::runtime_error("can't begin") ;

    InputIterator smallBegin = ft::next(smallchain.begin(), targetIndexBegin);
    InputIterator smallEnd = ft::next(smallchain.begin(), std::min(targetIndexEnd, smallchain.size()));

    InputIterator largeBegin = ft::next(largechain.begin(), targetIndexBegin);
    InputIterator largeEnd = ft::next(largechain.begin(), std::min(targetIndexEnd, largechain.size()));

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
        Node *ptr = smallchainSequence.back();
        // std::cout << "\x1b[2J\x1b[H";
        // std::cout << "small-chain:  "; ft::print(smallchain.begin(), smallchain.end(), true);
        // std::cout << "large-chain:  "; ft::print(largechain.begin(), largechain.end(), true);
        // std::cout << "mainchain:    "; ft::print(mainchain.begin(), mainchain.end());
        // std::cout << "small-queue:  "; ft::print(smallchainSequence.begin(), smallchainSequence.end(), true);
        // std::cout << "large-queue:  "; ft::print(largechainSequence.begin(), largechainSequence.end(), true);
        // std::cout << "insert-value: " << *ptr << std::endl;
        InputIterator insertPos = std::lower_bound(mainchain.begin(), mainchain.end(), ptr, Node::ptr_comp);
        mainchain.insert(insertPos, ptr);
        // std::cout << "inserted:     "; ft::print(mainchain.begin(), mainchain.end());
        // std::cout << "compcnt:      " << Node::comp_count << std::endl;
        // std::string line;
        // std::getline(std::cin, line);
        smallchainSequence.pop_back();
    }
    while (holdMainchain.size() != 0)
    {
        mainchain.push_back(holdMainchain.back());
        holdMainchain.pop_back();
    }
}
