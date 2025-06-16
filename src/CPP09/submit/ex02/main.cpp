#include "Node.hpp"
#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <vector>

int arg2number(const char *arg);
int _main(int argc, char *argv[]);
clock_t measurement_pmergeme(std::vector<Node *> &nodes, PmergeMe::Container &res);
double clock2us(clock_t clock);
template <typename InputIterator>
void print(InputIterator first, InputIterator last);

int main(int argc, char *argv[])
{
    try
    {
        _main(argc, argv);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}

int _main(int argc, char *argv[])
{
    if (argc == 1)
        return (0);
    std::vector<int> values(argc - 1);
    std::transform(argv + 1, argv + argc, values.begin(), arg2number);
    PmergeMe::Container nodes(values.size());
    std::transform(values.begin(), values.end(), nodes.begin(),
                   static_cast<Node *(*)(int)>(Node::create));

    clock_t spent_vector;

    PmergeMe::Container res;
    spent_vector = measurement_pmergeme(nodes, res);

    std::cout << "Before:  ";
    print(values.begin(), values.end());
    std::cout << "After:   ";
    PmergeMe::print(res.begin(), res.end());
    std::cout << std::fixed;
    std::cout << "Time to process a range of " << values.size()
              << " elements with std::vector : " << clock2us(spent_vector) << " us" << std::endl;
    PmergeMe::destroy_pairs(nodes.begin(), nodes.end());

    return (0);
}

int arg2number(const char *arg)
{
    int value;
    std::istringstream iss(arg);
    std::string leftover;

    value = -1;
    iss >> value;
    if (iss.fail())
        throw std::runtime_error("Invalid format number");
    else if (iss.peek() != -1)
    {
        std::getline(iss, leftover);
        throw std::runtime_error("Unable input: " + leftover);
    }
    else if (value < 0)
        throw std::runtime_error("You must specify positive number");
    return value;
}

clock_t measurement_pmergeme(std::vector<Node *> &nodes, PmergeMe::Container &res)
{
    clock_t start;
    clock_t end;

    start = clock();
    res = PmergeMe::pmergeme(nodes.begin(), nodes.end());
    end = clock();

    return end - start;
}

double clock2us(clock_t clock)
{
    return clock / (CLOCKS_PER_SEC / static_cast<double>(1000 * 1000));
}

template <typename InputIterator>
void print(InputIterator first, InputIterator last)
{
    InputIterator res;

    res = first;
    while (first != last)
    {
        std::cout << *first;
        ++first;
        if (first != last)
            std::cout << " ";
    }
    std::cout << std::endl;
}
