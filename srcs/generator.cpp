#include <n-puzzle.hpp>

int ft_random (int i)
{
	return std::rand()%i;
}

std::vector<unsigned int>			generator(unsigned int width_size)
{
	std::srand (unsigned (std::time(0)));
	std::vector<unsigned int>		v;

	for (unsigned int i = 0; i < width_size * width_size; i++)
		v.push_back(i);
	std::random_shuffle(v.begin(), v.end(), ft_random);

	return (v);
}
