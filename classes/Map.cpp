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

unsigned int					Map::distance(Map const &map2)
{
	static_cast<void>(map2);
	return (0);
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
