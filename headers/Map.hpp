// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/26 09:14:04 by dcojan            #+#    #+#             //
//   Updated: 2015/03/26 09:31:29 by dcojan           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <vector>
# include <cmath>

# define EUCLIDEAN 0
# define MANHATTAN 1

enum e_swap
{
	LEFT = 0,
	RIGHT,
	UP,
	DOWN
};

class Map
{

private:
	std::vector<unsigned int>		_map;
	unsigned int					_dim;
	bool							_outOfMap;
	std::size_t						_hash;
	static 	double					(Map::*f[])(Map const &map2);
	double							euclideanDistance(Map const &map2);
	double							manhattanDistance(Map const &map2);

public:
									Map(void);
	Map								&operator=(Map const &rhs);
									~Map(void);
									Map(Map const &copy);
									Map(std::vector<unsigned int>map, unsigned int dim);
									Map(Map const &copy, e_swap dir);

	double							calcDistance(Map const &map2, int distflag);

	unsigned int					getDim(void) const;
	void							setDim(unsigned int dim);
	std::vector<unsigned int> const	&	getMap(void) const;
	void							setMap(std::vector<unsigned int> map);
	bool							getOutOfMap(void) const;

	bool							moveLeft(void);
	bool							moveRight(void);
	bool							moveUp(void);
	bool							moveDown(void);

	void							reverseMap(void);
	void							createHash(void);
	std::size_t						getHash(void) const;
};

std::ostream					&operator<<(std::ostream &os, Map const &obj);

#endif
