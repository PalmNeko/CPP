#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <vector>

Span::Span()
    : _storage()
    , _max_size(0)
{}

Span::Span(const Span &other)
    : _storage()
    , _max_size(0)
{

    *this = other;
}

Span::~Span() {}

Span &Span::operator=(const Span &rhs)
{
    if (this != &rhs)
    {
    }
    return *this;
}

Span::Span(unsigned int n)
    : _storage()
    , _max_size(n)
{}

void Span::addNumber(int value)
{
    if (_storage.size() >= _max_size)
        throw std::exception();
    _storage.push_back(value);
}

unsigned int Span::shortestSpan(void) const
{
    if (_storage.size() < 2)
    {
        throw std::exception();
    }

    std::vector<int> copied = _storage;
    std::sort(copied.begin(), copied.end());

    std::vector<int>::const_iterator it = copied.begin();
    std::vector<int>::const_iterator ite = copied.end();
    unsigned int diff_min = std::numeric_limits<unsigned int>::max();
    unsigned int diff = 0;
    int a, b;
    it++;
    while (it != ite)
    {
        a = *(it - 1);
        b = *it;
        diff = std::max(a, b) - std::min(a, b);
        if (diff_min > diff)
            diff_min = diff;
        it++;
    }
    return diff_min;
}

unsigned int Span::longestSpan(void) const
{
    if (_storage.size() < 2)
        throw std::exception();

    std::vector<int>::const_iterator it = _storage.begin();
    std::vector<int>::const_iterator ite = _storage.end();

    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
    while (it != ite)
    {
        min = std::min(min, *it);
        max = std::max(max, *it);
        it++;
    }
    return (unsigned int)(max - min);
    return (0);
}
