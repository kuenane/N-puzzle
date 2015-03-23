// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   n-puzzle.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 12:38:40 by dcojan            #+#    #+#             //
//   Updated: 2015/03/23 16:14:52 by dcojan           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <n-puzzle.hpp>

bool			npuzzle(Map map, Map ref){
	Node					startNode = Node(map);
	Node					currentNode = Node(startNode);
	Node					node;
	std::vector<Node>		openList;
	std::vector<Node>		closedList;

//	int size = map.getDim();
// 	int y = 0;
// 	while (y < (size*size))
// 	{
// 		std::cout << map.getMap()[y] << " ";
// 		y++;
// 	}
	currentNode.setDistanceFrom(0);
	std::cout << "Initial map :" << std::endl << map << std::endl << std::endl;
	while (ref.euclideanDistance(currentNode.getMap()) != 0) //while distance is not same as ref
	{
		for (char i = 0; i < 4; i++) //for each direction
		{
			// create new map and new node in that direction
			node = Node(Map(currentNode.getMap(), static_cast<e_swap>(i)));

			// check if out of map (why not before creating new node ??)
 			if (node.getMap().getOutOfMap() == false)
 				continue;

			if (presentInVec(closedList, node.getMap()) == false) // if not in closed list
			{
				node.setParent(&currentNode);
				if (presentInVec(openList, node.getMap()) == false) // if NOT in open list
				{
					node.setDistanceTo(ref.euclideanDistance(node.getMap()));
					// node.setDistanceTo(ref.manhattanDistance(node.getMap()));
					node.setDistanceFrom(currentNode.getDistanceFrom() + 1);
					node.calcQuality();
					openList.push_back(node);
	            }
			}
		}

		if (openList.empty())
		{
			return false;
		}
		else
		{
			std::sort(openList.begin(), openList.end());
			node = openList.front();
			openList.erase(openList.begin());
			closedList.push_back(node);
			currentNode = node;
		}
	}

	// while (currentNode.getMap().euclideanDistance(map) != 0)
	// {
	// 	std::cout << currentNode.getMap() << std::endl;
	// 	std::cout << std::to_string(currentNode.getMap().euclideanDistance(map)) << std::endl << std::endl;

	// 	currentNode = currentNode.getParent();
	// }
	return true;
}
