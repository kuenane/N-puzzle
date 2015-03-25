// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MapCreator.class.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 10:04:27 by dcojan            #+#    #+#             //
//   Updated: 2015/03/25 12:01:01 by dcojan           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <MapCreator.class.hpp>

MapCreator::MapCreator()
{
}

MapCreator::~MapCreator()
{
}

std::vector<unsigned int>			MapCreator::split_line(std::string line, std::string delimiter, int size)
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

// bool			is_map_valid(std::vector<unsigned int>	&array, unsigned int size)
// {
// 	if (array.size() == 0)
// 		return false;
// 	for (unsigned int i = 0 ; i < (size * size - 1); i++)
// 	{
// 		for (unsigned int j = i + 1 ; j < (size * size); j++)
// 		{
// 			if (array[i] == array[j])
// 				return false;
// 		}
// 	}
// 	return true;
// }

Map				MapCreator::createMapFromArg(std::string arg)
{
	std::ifstream					ifs;

	ifs.open(arg, std::ifstream::in);
	if (!ifs.is_open())
	{
		std::cout << "Error can't open file" << std::endl;
		exit(EXIT_FAILURE);
	}
	Map map = getInputMap(ifs);
	ifs.close();
	return map;
}

bool			MapCreator::is_already_in(std::vector<unsigned int> &array, unsigned int nb)
{
	for (unsigned i = 0; i < array.size(); i++)
	{
		if (array[i] == nb)
			return true;
	}
	return false;
}

Map				MapCreator::createMapFromStdin()
{
	Map map = getInputMap(std::cin);
	return map;
}

unsigned int	MapCreator::getMapSize(std::istream& is)
{
	std::string						line;
	int								size = 0;

	while (!is.eof())
	{
		std::getline(is, line);
//		std::cout << line << std::endl;
		if (isdigit(line[0])){
			size = atoi(line.c_str());
			break;
		}
	}
	if (size < 3)
	{
		std::cout << "Error invalid map1" << std::endl;
		exit(EXIT_FAILURE);
	}
	return size;
}

Map				MapCreator::getInputMap(std::istream& is)
{
	std::string						line;
	std::vector<unsigned int>		tmp;
	std::vector<unsigned int>		check;

	int size = getMapSize(is);
	std::vector<unsigned int>		array((size * size), 0);
	for (int i = 0; i < size; i++)
	{
		std::getline(is, line);
		tmp = split_line(line, " ", size);
		for (int j = 0; j < size; j++)
		{
			if (is_already_in(check ,tmp[j]))
			{
				std::cout << "Error invalid map2" << std::endl;
				exit(EXIT_FAILURE);
			}
			// std::cout << "array[" << std::to_string(tmp[j]) << "] = " << std::to_string(size * i + j) << std::endl;
			array[tmp[j]] = size * i + j;
			check.push_back(tmp[j]);
		}
	}
	return Map(array, size);
}

Map				MapCreator::createRefMap(int size)
{
	std::vector<unsigned int>			map((size * size), 0);
	unsigned int						value = 1;
	Map									ref;

	for (int j = 0; j < (size / 2); j++)
	{
		for (int i = j; i < size - (j); i++)
		{
			map[(j * size) + i] = value != static_cast<unsigned int>(size * size)? value : 0;
			value++;
		}
		for (int i = 1 + j; i < (size - j); i++)
		{
			map[(i * size) + size - (1 + j)] = value != static_cast<unsigned int>(size * size)? value : 0;
			value++;
		}
		for (int i = (size - (2 + j)); i >= j; i--)
		{
			map[((size - (1 + j)) * size) + i] = value != static_cast<unsigned int>(size * size)? value : 0;
			value++;
		}
		for (int i = size - (2 + j); i > j; i--)
		{
			map[(i * size + j)] = value != static_cast<unsigned int>(size * size)? value : 0;
			value++;
		}
	}
	ref = Map(map, size);
	ref.reverseMap();
	return ref;
}
