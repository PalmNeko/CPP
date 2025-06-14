#include "Node.hpp"
#include <algorithm>

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
		_larger = &b;
	else
		_larger = &a;
	if (a < b)
		_smaller = &a;
	else
		_smaller = &b;
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
	return get_larger_value() < rhs.get_larger_value();
}

int Node::get_larger_value() const
{
	if (_larger != NULL)
		return _larger->get_larger_value();
	if (_smaller != NULL)
		return _smaller->get_larger_value();
	return _value;
}

Node *Node::create(Node &a, Node &b)
{
	return new Node(a, b);
}

Node *Node::create(Node *a, Node *b)
{
	return new Node(*a, *b);
}

std::ostream &operator<<(std::ostream &o, const Node& node)
{
	return o << node.get_larger_value();
}
