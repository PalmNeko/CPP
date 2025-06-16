#include "Node.hpp"
#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <list>
#include <sstream>
#include <vector>

struct PmergeMeResult
{
    public:
        std::vector<int> values;
        clock_t spent_time;
        int compcnt;

        template <typename InputIterator>
        PmergeMeResult(InputIterator first, InputIterator last)
            : spent_time(0), compcnt(0)
        {
            while (first != last)
            {
                values.push_back((*first)->get_larger_value());
                first++;
            }
        }
        ~PmergeMeResult() {}
        PmergeMeResult() {}
        PmergeMeResult &operator=(const PmergeMeResult &rhs)
        {
            if (this != &rhs)
            {
                values = rhs.values;
                spent_time = rhs.spent_time;
                compcnt = rhs.compcnt;
            }
            return *this;
        }
};

int _main(int argc, char *argv[]);
int arg2number(const char *arg);
template <class Container> PmergeMeResult measurement_pmergeme(std::vector<int> values);
double clock2us(clock_t clock);
template <typename InputIterator> void print(InputIterator first, InputIterator last);
void printResult(const char *containerName, PmergeMeResult &res);

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

    // run
    PmergeMeResult result_vector;
    PmergeMeResult result_list;

    result_vector = measurement_pmergeme<std::vector<Node *> >(values);
    result_list = measurement_pmergeme<std::list<Node *> >(values);

    // result
    std::cout << "Before:  ";
    print(values.begin(), values.end());
    std::cout << "After:   ";
    print(result_vector.values.begin(), result_vector.values.end());
    printResult("std::vector", result_vector);
    printResult("std::list", result_list);

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

template <class Container> PmergeMeResult measurement_pmergeme(std::vector<int> values)
{
    clock_t start;
    clock_t end;
    PmergeMe<Container> pm;
    typename PmergeMe<Container>::Container nodes(values.size());

    std::transform(values.begin(), values.end(), nodes.begin(),
                   static_cast<Node *(*)(int)>(Node::create));
    typename PmergeMe<Container>::Container res;

    Node::comp_count = 0;
    start = clock();
    res = pm.pmergeme(nodes.begin(), nodes.end());
    end = clock();

    PmergeMeResult result(res.begin(), res.end());
    result.spent_time = end - start;
    result.compcnt = Node::comp_count;
    std::cout << Node::comp_count << std::endl;
    pm.destroy_pairs(nodes.begin(), nodes.end());

    return result;
}

double clock2us(clock_t clock)
{
    return clock / (CLOCKS_PER_SEC / static_cast<double>(1000 * 1000));
}

template <typename InputIterator> void print(InputIterator first, InputIterator last)
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

void printResult(const char *containerName, PmergeMeResult &res)
{
    std::cout << std::fixed;
    std::cout << "Time to process a range of " << res.values.size() << " elements with "
              << containerName << " : " << clock2us(res.spent_time) << " us" << std::endl;
    std::cout << "comparision count: " << res.compcnt << std::endl;
}
