#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

std::string &trim(std::string &s);

std::vector<unsigned int>			split_line(std::string line, std::string delimiter, int size)
{
	std::vector<unsigned int>		ret;
	int						idx;
	int						i = 0;

	line = trim(line);

	while (i < size && (idx = line.find(delimiter)))
	{
		ret.push_back(atoi(line.substr(0, idx).c_str()));
		if (i < (size - 1))
			line = line.substr(idx, line.length() - idx);
		line = trim(line);
		i++;
	}
	return ret;
}

std::vector<unsigned int>				createMap(void)
{
	std::string						line;
	int								size = 0;

	std::vector<unsigned int>		array;
	std::vector<unsigned int>		tmp;
	std::getline(std::cin, line);
	std::getline(std::cin, line);

	size = std::atoi(line.c_str());

	for (int i = 0; i < size; i++)
	{
		std::getline (std::cin, line);
		tmp = split_line(line, " ", size);
		for (int j = 0; j < size; j++)
			array.push_back(tmp.at(j));
	}

	for (int i = 0; i < (size * size); i++)
	{
		std::cout << array.at(i);
		if (i < ((size * size) - 1))
			std::cout << " ";
	}
	std::cout << std::endl;

	return (array);
}


int main ()
{
	createMap();
	return (0);
}