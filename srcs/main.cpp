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
