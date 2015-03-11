#ifndef NODE_HPP
# define NODE_HPP

class Node
{

public:
						Node(void);
						~Node(void);
						Node(Node const &copy);
	Node 				&operator=(Node const &rhs);

};

#endif