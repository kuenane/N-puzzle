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
	_parent = rhs.getParent();
	return (*this);
}

Node				*Node::getParent(void) const
{
	return _parent;
}

void				Node::setParent(Node *parent)
{
	_parent = parent;
}
