#ifndef NODE_HPP
# define NODE_HPP

class Node
{

public:
	Node				_parent;
						Node(void);
						~Node(void);
						Node(Node const &copy);
	Node				&operator=(Node const &rhs);

	Node				getParent(void) const;
	void				setParent(Node parent);

};

#endif
