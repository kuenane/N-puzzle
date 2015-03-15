#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <Map.hpp>
#include <Node.hpp>

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

std::vector<unsigned int>				createMap(int size)
{
	std::string						line;

	std::vector<unsigned int>		array;
	std::vector<unsigned int>		tmp;

	for (int i = 0; i < size; i++)
	{
		std::getline (std::cin, line);
		tmp = split_line(line, " ", size);
		for (int j = 0; j < size; j++)
			array.push_back(tmp.at(j));
	}
	return (array);
}

std::vector<unsigned int>				createRefMap(int size)
{
	std::vector<unsigned int>			map((size * size), 0);
	unsigned int						value = 1;


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

	return (map);
}


bool						presentInVec(std::vector<Node> v, Map map)
{
	for(std::vector<Node>::iterator it=v.begin(); it!=v.end(); ++it)
	{
		Node& el = *it;
		if (el.getMap().manhattanDistance(map) == 0)
			return (true);
	}
	return (false);
}


int main ()
{
	int								dim = 0;
	std::string						line;

	std::getline(std::cin, line);
	std::cout << line << std::endl;
	std::getline(std::cin, line);
	dim = atoi(line.c_str());

	Map			map(createMap(dim), dim);
	Map			ref(createRefMap(dim), dim);

	Node		startNode = Node(map);
	Node		currentNode = Node(startNode);
	Node		node;

	std::vector<Node> openList;
	std::vector<Node> closedList;

	std::cout << "Initial map :" << std::endl <<  map << std::endl << std::endl;
	while (ref.manhattanDistance(currentNode.getMap()) != 0)
	{
		for (char i = 0; i < 4; i++)
		{
			node = Node(Map(currentNode.getMap(), static_cast<e_swap>(i)));
			if ( node.getMap().manhattanDistance(currentNode.getMap()) == 0)
				continue;

			if (!presentInVec(closedList, currentNode.getMap()))
			{
				std::cout << "Here " << std::to_string(i) << std::endl;
				if (presentInVec(openList, currentNode.getMap()))
					node.setParent(&currentNode);
			
				else
				{
					node.setParent(&currentNode);
                	node.setQuality(ref.manhattanDistance(node.getMap()) );
					openList.push_back(node);
	            }
			}
		}

		if (openList.empty())
		{
			std::cerr << "No solution." << std::endl;
			return (-1);
		}
		else
		{
			std::sort(openList.begin(), openList.end(), less_than_key());
			node = openList.front();
			openList.erase(openList.begin());
			closedList.push_back(node);
			currentNode = node;
			std::cout << currentNode.getMap() << std::endl << std::endl;
		}

	}

	// std::cout << closedList << std::endl;

	return (0);
}
