// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 09:54:52 by dcojan            #+#    #+#             //
//   Updated: 2015/03/23 16:22:58 by dcojan           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <n-puzzle.hpp>
#include <MapCreator.class.hpp>

// // C++ program to check if a given instance of 8 puzzle is solvable or not
// #include <iostream>
// using namespace std;
 
// A utility function to count inversions in given array 'arr[]'
int getInvCount(const std::vector<unsigned int> &map)
{
    int inv_count = 0;
    for (int i = 0; i < (int)map.size() - 1; i++)
        for (int j = i+1; j < (int)map.size(); j++)
             // Value 0 is used for empty space
             if (map[j] && map[i] &&  map[i] > map[j])
                  inv_count++;
    return inv_count;
}
 
// This function returns true if given 8 puzzle is solvable.
bool isSolvable(Map &map)
{
	map.reverseMap();
    // Count inversions in given 8 puzzle
    int invCount = getInvCount(map.getMap());
 
    // return true if inversion count is even.
    map.reverseMap();
    // Works only with odd width map
    // For even width map : https://www.cs.bham.ac.uk/~mdr/teaching/modules04/java2/TilesSolvability.html
    return (invCount%2 == 1);
}
 
// /* Driver progra to test above functions */
// int main(int argv, int** args)
// {
//   int puzzle[3][3] =  {{1, 8, 2},
//                       {0, 4, 3},  // Value 0 is used for empty space
//                       {7, 6, 5}};
//   isSolvable(puzzle)? cout << "Solvable":
//                       cout << "Not Solvable";
//   return 0;
// }





int main (int ac, char *av[])
{
	MapCreator						mapcreator;
	Map								map;
	Map								ref;

	bool verbose = false;
	if (ac == 3 && (strcmp(av[2], "-v") == 0 || strcmp(av[2], "--verbose") == 0))
		verbose = true;
	// do try/catch here

	map = (ac > 1) ? mapcreator.createMapFromArg(av[1]): mapcreator.createMapFromStdin();
	if (!isSolvable(map))
	{
		std::cout << "Map unsolvable !" << std::endl;
		return (0);
	}
	// and here
	ref = mapcreator.createRefMap(map.getDim());
	if (npuzzle(map, ref, verbose))
	{
		std::cout << "Resolu !" << std::endl;
	}
	else
	{
		std::cerr << "No solution." << std::endl;
	}
	return (0);
}
