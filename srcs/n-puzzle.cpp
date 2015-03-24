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


void			printSolution(Node *node, int &count, bool verbose)
{
	count += 1;
	if (node->getParent() != NULL)
		printSolution(node->getParent(), count, verbose);
	if (verbose)
		std::cout << node->getMap() << std::endl << std::endl;
}


bool			npuzzle(Map map, Map ref, bool verbose)
{
	Node					startNode = Node(map);
	Node					*currentNode = new Node(startNode);
	Node					*node;
	std::vector<Node*>		openList;
	std::vector<Node*>		closedList;

	currentNode->setDistanceFrom(0);
	currentNode->setDistanceTo(ref.euclideanDistance(currentNode->getMap()));
	int k = 0;
	while (currentNode->getDistanceTo() != 0) //while distance is not same as ref
	{
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
	// std::cout << "Nb of loops : " << k << std::endl;

	int count = -1; // -1 to count the number of movements and not array state
	printSolution(currentNode, count, verbose);
	std::cout << "Size of open list : " << openList.size() << std::endl;
	std::cout << "Number of moves : " << count << std::endl;
	return true;
}
