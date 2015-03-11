#include <Map.hpp>

Map::Map(void)
{
	return ;
}

Map::~Map(void)
{
	return ;
}

Map::Map(Map const &copy)
{
	*this = copy;
}

Map					&Map::operator=(Map const &rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

Map::Map(std::vector<unsigned int>map, unsigned int dim)
{
	setMap(map);
	setDim(dim);
}

unsigned int					Map::getDim(void) const
{
	return (_dim);
}

void							Map::setDim(unsigned int dim)
{
	_dim = dim;
}

std::vector<unsigned int>		Map::getMap(void) const
{
	return (_map);
}

void							Map::setMap(std::vector<unsigned int>map)
{
	_map = map;
}

std::ostream					&operator<<(std::ostream &os, Map const &obj)
{
	for (unsigned int i = 0; i < (obj.getDim() * obj.getDim()); i++)
	{
		if (i > 0 && (i % obj.getDim()) == 0)
			os << std::endl;
		os << obj.getMap().at(i);
		if (i < ((obj.getDim() * obj.getDim()) - 1))
			os << " ";
	}
	return (os);
}

unsigned int					Map::distance(Map const &map2)
{
	unsigned int				j;
	unsigned int				xd;
	unsigned int				yd;
	double 						distance = 0;

	for (unsigned int i = 0; i < (_dim * _dim); i++)
	{
		j = 0;
		while (map2.getMap().at(j) != _map.at(i))
			j++;
		xd = (i % _dim) - (j % _dim);
		yd = (i / _dim) - (j / _dim);
		distance += std::sqrt((xd * xd) + (yd * yd));
	}

	return (0);
}
