#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <vector>
# include <cmath>

enum e_swap
{
	LEFT = 0,
	UP,
	RIGHT,
	DOWN
};

class Map
{

private:
									Map(void);
	Map								&operator=(Map const &rhs);
	std::vector<unsigned int>		_map;
	unsigned int					_dim;

public:
									~Map(void);
									Map(Map const &copy);
									Map(std::vector<unsigned int>map, unsigned int dim);
									Map(Map const &copy, e_swap dir);

	double							euclideanDistance(Map const &map2);
	double							manhattanDistance(Map const &map2);

	unsigned int					getDim(void) const;
	void							setDim(unsigned int dim);
	std::vector<unsigned int>		getMap(void) const;
	void							setMap(std::vector<unsigned int> map);

	void							moveLeft(void);
	void							moveRight(void);
	void							moveUp(void);
	void							moveDown(void);

};

std::ostream					&operator<<(std::ostream &os, Map const &obj);

#endif
