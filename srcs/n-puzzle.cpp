// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   n-puzzle.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 12:38:40 by dcojan            #+#    #+#             //
//   Updated: 2015/03/24 16:11:33 by dcojan           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <n-puzzle.hpp>

bool			npuzzle(Map map, Map ref){
	Node					startNode = Node(map);
	Node					*currentNode = new Node(startNode);
	Node					*node;
	std::vector<Node*>		openList;
	std::vector<Node*>		closedList;

	std::cout << "REF MAP " << std::endl;
	std::cout << ref << std::endl;
	currentNode->setDistanceFrom(0);
	std::cout << "Initial map :" << std::endl << map << std::endl << std::endl;
	int k = 0;
	while (ref.euclideanDistance(currentNode->getMap()) != 0) //while distance is not same as ref
	{
//		printf("Adresse : %p\n", currentNode);
		for (char i = 0; i < 4; i++) //for each direction
		{
			// create new map and new node in that direction
			node = new Node(Map(currentNode->getMap(), static_cast<e_swap>(i)));

			// check if out of map (why not before creating new node ??)
 			if (node->getMap().getOutOfMap() == false)
			{
				delete node;
 				continue;
			}
//			std::cout << node->getMap() << std::endl;
			if (presentInVec(closedList, node->getMap()) == false) //if not in closed list
			{
				node->setParent(currentNode);
				if (presentInVec(openList, node->getMap()) == false) //if NOT in open list
				{
					node->setDistanceTo(ref.euclideanDistance(node->getMap()));
//					std::cout  << "Distance : "<< node->getDistanceTo() << std::endl;
//					node.setDistanceTo(ref.manhattanDistance(node.getMap()));
					node->setDistanceFrom(currentNode->getDistanceFrom() + 1);
					openList.push_back(node);
//					std::cout << "Quality : "<< node->getQuality() << std::endl;
	            }
			}
		}

		if (openList.empty())
		{
			return false;
		}
		else
		{
			std::sort(openList.begin(), openList.end(), Node::PointerCompare());
			node = openList.front();
// 			std::cout << "Choosen one !!\n : "<< node->getMap() << std::endl;

			openList.erase(openList.begin());
			closedList.push_back(node);
			currentNode = node;
		}

		k++;
// 		if (k == 10)
// 			break;
	}
	std::cout << "Nb of loops : " << k << std::endl;

	// while (currentNode.getMap().euclideanDistance(map) != 0)
	// {
	// 	std::cout << currentNode.getMap() << std::endl;
	// 	std::cout << std::to_string(currentNode.getMap().euclideanDistance(map)) << std::endl << std::endl;

	// 	currentNode = currentNode.getParent();
	// }
	return true;
}
