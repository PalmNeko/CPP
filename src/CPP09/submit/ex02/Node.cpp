#include "Node.hpp"
#include <algorithm>

Node::Node()
	: _value(0), _larger(NULL), _smaller(NULL)
{}

Node::Node(const Node &other)
	: _value(0), _larger(NULL), _smaller(NULL)
{
	*this = other;
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

Node &Node::operator=(const Node &rhs)
{
	if (this != &rhs) {
		Node *larger;
		Node *smaller;

		larger = NULL;
		smaller = NULL;
		if (rhs._larger != NULL)
			larger = new Node(*rhs._larger);
		try {
			if (rhs._smaller != NULL)
				smaller = new Node(*rhs._smaller);
		}
		catch (const std::exception &e)
		{
			delete larger;
			throw ;
		}
		delete _larger;
		delete _smaller;
		_larger = larger;
		_smaller = smaller;
		_value = rhs._value;		
	}
	return *this;
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

Node *Node::create(int a, int b)
{
	Node *nodeA;
	Node *nodeB;
	
	nodeA = NULL;
	nodeB = NULL;
	try {
		nodeA = new Node(a);
		nodeB = new Node(b);
	}
	catch (const std::exception &e)
	{
		delete nodeA;
		delete nodeB;
	}
	return Node::create(*nodeA, *nodeB);
}

Node *Node::create(Node &a, Node &b)
{
	return new Node(a, b);
}

Node *Node::create(Node *a, Node *b)
{
	return new Node(*a, *b);
}

std::ostream &operator<<(const std::ostream &o, const Node& node)
{
	return o << node.get_larger_value();
}
