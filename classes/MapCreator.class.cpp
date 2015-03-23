// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MapCreator.class.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 10:04:27 by dcojan            #+#    #+#             //
//   Updated: 2015/03/23 12:35:38 by dcojan           ###   ########.fr       //
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

Map				MapCreator::createMapFromArg(std::string arg)
{
	std::string						line;
	std::vector<unsigned int>		tmp;
	int								size;
	std::ifstream					ifs;

	ifs.open(arg, std::ifstream::in);
	std::getline(ifs, line);
	std::cout << line << std::endl;
	std::getline(ifs, line);
	size = atoi(line.c_str());

	std::vector<unsigned int>		array((size * size), 0);
	for (int i = 0; i < size; i++)
	{
		std::getline(ifs, line);
		tmp = split_line(line, " ", size);
		for (int j = 0; j < size; j++)
		{
			// std::cout << "array[" << std::to_string(tmp[j]) << "] = " << std::to_string(size * i + j) << std::endl;
			array[tmp[j]] = size * i + j;
		}
	}
	ifs.close();
	return Map(array, size);
}

Map				MapCreator::createMapFromStdin()
{
	std::string						line;
	std::vector<unsigned int>		tmp;
	int								size;

	std::getline(std::cin, line);
	std::cout << line << std::endl;
	std::getline(std::cin, line);
	size = atoi(line.c_str());

	std::vector<unsigned int>		array((size * size), 0);
	for (int i = 0; i < size; i++)
	{
		std::getline (std::cin, line);
		tmp = split_line(line, " ", size);
		for (int j = 0; j < size; j++)
		{
			// std::cout << "array[" << std::to_string(tmp[j]) << "] = " << std::to_string(size * i + j) << std::endl;
			array[tmp[j]] = size * i + j;
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
