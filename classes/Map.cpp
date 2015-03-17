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

Map::Map(Map const &copy, e_swap dir)
{

	bool	(Map::*moveArray[])(void) = {&Map::moveLeft, &Map::moveRight, &Map::moveUp, &Map::moveDown};
	*this = copy;
	(void)dir;
	(this->*moveArray[static_cast<int>(dir)])();
}

Map					&Map::operator=(Map const &rhs)
{
	_map = rhs.getMap();
	_dim = rhs.getDim();
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
	Map map_tmp = Map(obj);

	map_tmp.reverseMap();
	for (unsigned int i = 0; i < (map_tmp.getDim() * map_tmp.getDim()); i++)
	{
		if (i > 0 && (i % map_tmp.getDim()) == 0)
			os << std::endl;
		os << map_tmp.getMap().at(i);
		if (i < ((map_tmp.getDim() * map_tmp.getDim()) - 1))
			os << " ";
	}
	return (os);
}

double							Map::euclideanDistance(Map const &map2)
{
	unsigned int				xd;
	unsigned int				yd;
	double 						distance = 0;

	for (unsigned int i = 0; i < (_dim * _dim); i++)
	{
		xd = (_map[i] % _dim) - (map2.getMap()[i] % _dim);
		yd = (_map[i] / _dim) - (map2.getMap()[i] / _dim);
		distance += std::sqrt((xd * xd) + (yd * yd));
	}
	return (distance);
}

double							Map::manhattanDistance(Map const &map2)
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
		xd = abs((i % _dim) - (j % _dim));
		yd = abs((i / _dim) - (j / _dim));
		distance += (xd + yd);
	}
	return (distance);
}

bool							Map::moveLeft(void)
{
	unsigned int i = _map[0];

	if (i % _dim > 0)
	{
		int k = 0;
		while (_map[k] != i - 1)
			k++;
		_map[0] = _map[0] + _map[k];
		_map[k] = _map[0] - _map[k];
		_map[0] = _map[0] - _map[k];
		return (true);
	}
	return (false);
}

bool							Map::moveRight(void)
{
	unsigned int i = _map[0];

	if (i % _dim < (_dim - 1))
	{
		int k = 0;
		while (_map[k] != i + 1)
			k++;
		_map[0] = _map[0] + _map[k];
		_map[k] = _map[0] - _map[k];
		_map[0] = _map[0] - _map[k];
		return (true);
	}
	return (false);
}

bool							Map::moveUp(void)
{
	unsigned int i = _map[0];

	if (i / _dim > 0)
	{
		int k = 0;
		while (_map[k] != i - _dim)
			k++;
		_map[0] = _map[0] + _map[k];
		_map[k] = _map[0] - _map[k];
		_map[0] = _map[0] - _map[k];
		return (true);
	}
	return (false);
}

bool							Map::moveDown(void)
{
	unsigned int i = _map[0];

	if (i / _dim < (_dim - 1))
	{
		int k = 0;
		while (_map[k] != i + _dim)
			k++;
		_map[0] = _map[0] + _map[k];
		_map[k] = _map[0] - _map[k];
		_map[0] = _map[0] - _map[k];
		return (true);
	}
	return (false);
}

void							Map::reverseMap(void)
{
	std::vector<unsigned int>	newMap((_dim * _dim), 0);

	for(unsigned int i = 0; i < _map.size(); i++)
		newMap[_map[i]] = i;

	_map = newMap;
}