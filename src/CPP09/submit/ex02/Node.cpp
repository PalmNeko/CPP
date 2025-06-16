#include "Node.hpp"
#include <algorithm>

int Node::comp_count = 0;

Node::Node()
	: _value(0), _larger(NULL), _smaller(NULL)
{}

Node::Node(const Node &)
	: _value(0), _larger(NULL), _smaller(NULL)
{
	throw std::exception();
}


Node::Node(int a)
	: _value(a), _larger(NULL), _smaller(NULL)
{}

Node::Node(Node &a, Node &b)
	: _value(0), _larger(NULL), _smaller(NULL)
{
	if (a < b)
	{
		_smaller = &a;
		_larger = &b;
		_value = b._value;
	}
	else
	{
		_smaller = &b;
		_larger = &a;
		_value = a._value;
	}
}

Node::~Node()
{
}

Node &Node::operator=(const Node &)
{
	throw std::exception();
}

bool Node::operator<(const Node& rhs) const
{
	comp_count += 1;
	return _value < rhs._value;
}

bool Node::operator<(const Node* rhs) const
{
	return *this < *rhs;
}

int Node::getValue() const
{
	return _value;
}

Node *Node::getLarger()
{
	return _larger;
}

const Node *Node::getLarger() const
{
	return _larger;
}

Node *Node::getSmaller()
{
	return _smaller;
}

const Node *Node::getSmaller() const
{
	return _smaller;
}

Node *Node::create(Node &a, Node &b)
{
	return new Node(a, b);
}

Node *Node::create(Node *a, Node *b)
{
	return new Node(*a, *b);
}

Node *Node::create(int value)
{
	return new Node(value);
}

std::ostream &operator<<(std::ostream &o, const Node& node)
{
	return o << node.getValue();
}
