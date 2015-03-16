#ifndef NODE_HPP
# define NODE_HPP

# include <Map.hpp>

class Node
{

private:
	Map					_map;
	double				_quality;
	Node				*_parent;

public:
						Node(void);
						~Node(void);
						Node(Node const &copy);
	Node				&operator=(Node const &rhs);
						Node(Map map);

	Node				*getParent(void) const;
	void				setParent(Node *parent);
	Map					getMap(void) const;
	void				setMap(Map map);
	double				getQuality(void) const;
	void				setQuality(double quality);

 	bool operator<(const Node& st) const
	{
		// std::cout << "q1 : " << _quality << std::endl;
		// std::cout << "q2 : " << st.getQuality() << std::endl;
 		return _quality < st.getQuality();
	}
};


#endif
