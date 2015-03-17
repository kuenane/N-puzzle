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
	_map = rhs.getMap();
	_quality = rhs.getQuality();
	return (*this);
}

Node::Node(Map map)
{
	_map = map;
}


Node				*Node::getParent(void) const
{
	return _parent;
}

void				Node::setParent(Node *parent)
{
	_parent = parent;
}

Map					Node::getMap(void) const
{
	return _map;
}

void				Node::setMap(Map map)
{
	_map = map;
}

double				Node::getQuality(void) const
{
	return _quality;
}

void				Node::setQuality(double quality)
{
	_quality = quality;
}

void				Node::calcQuality(void)
{
	_quality = _distanceFrom + _distanceTo;
}

double				Node::getDistanceFrom(void) const
{
	return _distanceFrom;
}

void				Node::setDistanceFrom(double distance)
{
	_distanceFrom = distance;
}

double				Node::getDistanceTo(void) const
{
	return _distanceTo;
}

void				Node::setDistanceTo(double distance)
{
	_distanceTo = distance;
}

// void				Node::updateEuclideanDistance(Map &ref, Node &old, e_swap i)
// {
// 	if (i == LEFT)
// 	{
// 	}
// 	else if (i == RIGHT)
// 	{
// 	}
// 	else if (i == UP)
// 	{
// 	}
// 	else
// 	{
// 	}
// }
