#ifndef NODE_HPP
# define NODE_HPP

#include <iostream>

class Node
{
	private:
		int _value;
		Node *_larger;
		Node *_smaller;
	protected:
	public:
		Node();
		Node(const Node &other);
		Node(int a);
		Node(Node &a, Node &b);

		virtual ~Node();
		Node &operator=(const Node &rhs);
		bool operator<(const Node& rhs) const;

		int get_larger_value() const;
		static Node *create(int a, int b);
		static Node *create(Node &a, Node &b);
		static Node *create(Node *a, Node *b);
};

std::ostream &operator<<(const std::ostream &o, const Node& node);



#endif // NODE_HPP
