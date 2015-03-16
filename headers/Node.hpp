#ifndef NODE_HPP
# define NODE_HPP

# include <Map.hpp>

class Node
{

private:
	Map					_map;
	Node				*_parent;
	double				_quality;
	double				_distanceFrom;
	double				_distanceTo;

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
	void				calcQuality(void);
	double				getDistanceFrom(void) const;
	void				setDistanceFrom(double distance);
	double				getDistanceTo(void) const;
	void				setDistanceTo(double distance);

 	bool operator<(const Node& st) const
	{
 		return _quality < st.getQuality();
	}
};


#endif
