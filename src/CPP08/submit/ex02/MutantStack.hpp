#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <deque>
# include <stack>

template <class T, class Container = std::deque<T> > class MutantStack : public std::stack<T, Container>
{
	public:

		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		MutantStack();
		MutantStack(const MutantStack &other);
		virtual ~MutantStack();
		MutantStack &operator=(const MutantStack &rhs);

		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
};

#include "MutantStack.tpp"

#endif // MUTANT_STACK_HPP
