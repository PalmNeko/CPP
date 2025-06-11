#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <limits>
#include <numeric>
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

// ヒープを使ってデータを保存しておけば早そう std::push_heap
// データ順序が保存されないのが問題になる可能性があるので不採用
// 一度計算したらデータが追加されるまで処理しない方が早そう
// 変更分だけ計算できればなおよい
unsigned int Span::shortestSpan(void) const
{
    if (_storage.size() < 2)
    {
        throw std::exception();
    }

    std::vector<int> copied = _storage;
    std::sort(copied.begin(), copied.end());

    std::vector<unsigned int> result(copied.size());
    std::adjacent_difference(copied.begin(), copied.end(), result.begin());
    result[0] = std::numeric_limits<unsigned int>::max();
    std::vector<unsigned int>::const_iterator shortestSpan = std::min_element(result.begin(), result.end());
    return *shortestSpan;
}

unsigned int Span::longestSpan(void) const
{
    if (_storage.size() < 2)
        throw std::exception();

    std::vector<int>::const_iterator min = std::min_element(_storage.begin(), _storage.end());
    std::vector<int>::const_iterator max = std::max_element(_storage.begin(), _storage.end());

    return (unsigned int)(*max - *min);
}
