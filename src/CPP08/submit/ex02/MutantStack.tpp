#include "MutantStack.hpp"

template <class T, class Container>
MutantStack<T, Container>::MutantStack()
    : std::stack<T, Container>()
{}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other)
    : std::stack<T, Container>(other)
{
}

template <class T, class Container> MutantStack<T, Container>::~MutantStack() {}

template <class T, class Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack &rhs)
{
    if (this != &rhs)
    {
        std::stack<T, Container>::operator=(rhs);
    }
    return *this;
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
    return this->c.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
    return this->c.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
    return this->c.end();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
    return this->c.end();
}
