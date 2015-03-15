#ifndef NODE_HPP
# define NODE_HPP

# include <Map.hpp>

class Node
{

private:
	Map					_map;
	Node				*_parent;
	double				_quality;


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

};

struct less_than_key
{
    inline bool operator() (const Node& struct1, const Node& struct2)
    {
        return (struct1.getQuality() < struct2.getQuality());
    }
};

#endif
