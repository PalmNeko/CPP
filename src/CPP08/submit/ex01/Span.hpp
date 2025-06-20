#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <functional>

class Span
{
    private:
        std::vector<int> _storage;
        unsigned int _max_size;

    public:
        Span();
        Span(const Span &other);
        virtual ~Span();
        Span &operator=(const Span &rhs);

        Span(unsigned int n);
        template <class InputIterator> Span(InputIterator first, InputIterator last);

        void addNumber(int value);
        template <class InputIterator> void addNumber(InputIterator first, InputIterator last);
        unsigned int shortestSpan(void) const;
        unsigned int longestSpan(void) const;
};

template <class InputIterator>
Span::Span(InputIterator first, InputIterator last)
    : _storage(first, last)
    , _max_size(_storage.size())
{}

template <class InputIterator> void Span::addNumber(InputIterator first, InputIterator last)
{
    _storage.assign(first, last);
}

#endif // SPAN_HPP
