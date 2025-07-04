#ifndef NODE_HPP
# define NODE_HPP

#include <iostream>

class Node
{
	private:
		int _value;
		Node *_larger;
		Node *_smaller;

		Node();
		Node(const Node &other);
		Node &operator=(const Node &rhs);

	public:
		static int comp_count;
		Node(int a);
		Node(Node &a, Node &b);

		virtual ~Node();
		bool operator<(const Node& rhs) const;
		bool operator<(const Node* rhs) const;

		int getValue() const;

		Node *getLarger();
		const Node *getLarger() const;
		Node *getSmaller();
		const Node *getSmaller() const;

		static Node *create(Node &a, Node &b);
		static Node *create(Node *a, Node *b);
		static Node *create(int value);
		static bool ptr_comp(const Node *a, const Node * b);
};

std::ostream &operator<<(std::ostream &o, const Node& node);
std::ostream &operator<<(std::ostream &o, const Node* node);



#endif // NODE_HPP
