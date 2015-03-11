#include <Node.hpp>

Node::Node(void)
{
	return ;
}


Node::~Node(void)
{
	return ;
}


Node::Node(Node const &copy)
{
	*this = copy;
}


Node 				&Node::operator=(Node const &rhs)
{
	static_cast<void>(rhs);
	return (*this);
}
