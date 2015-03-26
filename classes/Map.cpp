// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 12:47:46 by dcojan            #+#    #+#             //
//   Updated: 2015/03/26 10:43:38 by dcojan           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <Map.hpp>
#include <boost/functional/hash.hpp>

Map::Map(void){
	_outOfMap = true;
}

Map::~Map(void){
}

Map::Map(Map const &copy){
	*this = copy;
}

Map::Map(Map const &copy, e_swap dir)
{
	bool	(Map::*moveArray[])(void) = {&Map::moveLeft, &Map::moveRight, &Map::moveUp, &Map::moveDown};
	*this = copy;
	_outOfMap = (this->*moveArray[static_cast<int>(dir)])();
	createHash();
}

Map					&Map::operator=(Map const &rhs)
{
	_map = rhs.getMap();
	_dim = rhs.getDim();
	_outOfMap = rhs.getOutOfMap();
	_hash = rhs.getHash();
	return (*this);
}

Map::Map(std::vector<unsigned int>map, unsigned int dim)
{
	setMap(map);
	setDim(dim);
	_outOfMap = true;
	createHash();
}

unsigned int					Map::getDim(void) const{
	return (_dim);
}

void							Map::setDim(unsigned int dim){
	_dim = dim;
}

std::vector<unsigned int>	const &	Map::getMap(void) const{
	return (_map);
}

void							Map::setMap(std::vector<unsigned int>map){
	_map = map;
	createHash();
}

bool							Map::getOutOfMap(void) const{
	return (_outOfMap);
}

std::ostream					&operator<<(std::ostream &os, Map const &obj){
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

static int square(int n)
{
    // Base case
    if (n==0) return 0;
    // Handle negative number
    if (n < 0) n = -n;
    // Get floor(n/2) using right shift
    int x = n>>1;
    // If n is odd
    if (n&1)
        return ((square(x)<<2) + (x<<2) + 1);
    else // If n is even
        return (square(x)<<2);
}

double							Map::euclideanDistance(Map const &map2){
	unsigned int				xd;
	unsigned int				yd;
	unsigned int				a;
	unsigned int				b;
	double 						distance = 0;
	unsigned int				cases = _dim * _dim;
	std::vector<unsigned int>	mapmap2 = map2.getMap();

	for (unsigned int i = 0; i < cases; i++)
	{
		a = _map[i];
		b = mapmap2[i];
		xd = (a % _dim) - (b % _dim);
		yd = (a / _dim) - (b / _dim);
		distance += std::sqrt(square(xd) + square(yd));
	}
	return (distance);
}
double		(Map::*Map::f[])(Map const &map2) = {
	&Map::euclideanDistance,
	&Map::manhattanDistance,
	&Map::hammingDistance};

double							Map::manhattanDistance(Map const &map2){
	unsigned int				xd;
	unsigned int				yd;
	double 						distance = 0;
	unsigned int				cases = _dim * _dim;
	std::vector<unsigned int>	mapmap2 = map2.getMap();


	for (unsigned int i = 0; i < cases; i++)
	{
		xd = abs((_map[i] % _dim) - (mapmap2[i] % _dim));
		yd = abs((_map[i] / _dim) - (mapmap2[i] / _dim));
		distance += (xd + yd);
	}
	return (distance);
}

double							Map::hammingDistance(Map const &map2){
	double 						distance = 0;
	unsigned int				cases = _dim * _dim;
	std::vector<unsigned int>	mapmap2 = map2.getMap();

	for (unsigned int i = 0; i < cases; i++)
	{
		if (_map[i] != mapmap2[i])
			distance++;
	}
	return (distance);
}

double							Map::calcDistance(Map const &map2, int distflag){

	return (this->*f[distflag])(map2);
}

bool							Map::moveLeft(void){
	unsigned int i = _map[0];

	if (i % _dim > 0)
	{
		int k = 1;
		while (_map[k] != i - 1)
			k++;
		_map[0] = _map[k];
		_map[k] = i;
		return (true);
	}
	return (false);
}

bool							Map::moveRight(void){
	unsigned int i = _map[0];

	if (i % _dim < (_dim - 1))
	{
		int k = 1;
		while (_map[k] != i + 1)
			k++;
		_map[0] = _map[k];
		_map[k] = i;
		return (true);
	}
	return (false);
}

bool							Map::moveUp(void){
	unsigned int i = _map[0];

	if (i >= _dim)
	{
		int k = 1;
		while (_map[k] != i - _dim)
			k++;
		_map[0] = _map[k];
		_map[k] = i;
		return (true);
	}
	return (false);
}

bool							Map::moveDown(void){
	unsigned int i = _map[0];

	if (i / _dim < (_dim - 1))
	{
		int k = 1;
		while (_map[k] != i + _dim)
			k++;
		_map[0] = _map[k];
		_map[k] = i;
		return (true);
	}
	return (false);
}

void							Map::reverseMap(void){
	std::vector<unsigned int>	newMap((_dim * _dim), 0);

	for(unsigned int i = 0; i < _map.size(); i++)
		newMap[_map[i]] = i;
	_map = newMap;
}

void							Map::createHash(void){
	_hash = boost::hash_range(_map.begin(), _map.end());
}

std::size_t						Map::getHash(void) const{
	return _hash;
}
