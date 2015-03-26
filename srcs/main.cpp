// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 09:54:52 by dcojan            #+#    #+#             //
//   Updated: 2015/03/26 10:09:51 by dcojan           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <n-puzzle.hpp>
#include <MapCreator.class.hpp>

int main (int ac, char *av[])
{
	MapCreator						mapcreator;
	Map								map;
	Map								ref;
	bool							verbose = false;
	int								distflag = EUCLIDEAN;
	bool							maparg;
	for (int i = 1; i < ac; i++)
	{
		if ((strcmp(av[i], "-v") == 0 || strcmp(av[i], "--verbose") == 0))
			verbose = true;
		else if ((strcmp(av[i], "-h") == 0 || strcmp(av[i], "--help") == 0))
		{
			std::cout << "usage: n_puzzle [-h] [-v] [-d DISTANCE] filename\n"
					  << "usage: [stdin] | n_puzzle [-h] [-v] [-d DISTANCE]\n\n"
					  << "optional argument:\n"
					  << "  -h, --help\t\t\t\tShow this message and exit.\n"
					  << "  -v, --verbose\t\t\t\tVerbose mode.\n"
					  << "  -d DISTANCE, --distance DISTANCE\tDistance algorithm\n"
					  << "  DISTANCE (default 0):\n\t\t0 for euclidean\n\t\t1 for manhattan\n"
					  << std::endl;
			exit(EXIT_SUCCESS);
		}
		else if ((strcmp(av[i], "-d") == 0 || strcmp(av[i], "--distance") == 0))
		{
			if (++i >= ac)
			{
				std::cout << "Error: expect 0 or 1 after -d or --distance."<< std::endl;
				exit(EXIT_FAILURE);
			}
			if (strcmp(av[i], "0") == 0)
				distflag = EUCLIDEAN;
			if (strcmp(av[i], "1") == 0)
				distflag = MANHATTAN;
		}
		else
		{
			maparg = true;
			map = mapcreator.createMapFromArg(av[1]);
			if (++i < ac)
			{
				std::cout << "Error: unexpected argument"<< std::endl;
				exit(EXIT_FAILURE);
			}
		}
	}
	if (maparg ==false)
		map = mapcreator.createMapFromStdin();
	if (!isSolvable(map))
	{
		std::cout << "Map unsolvable !" << std::endl;
		return (0);
	}
	ref = mapcreator.createRefMap(map.getDim());

	if (npuzzle(map, ref, verbose, distflag))
		std::cout << "Resolu !" << std::endl;
	else
		std::cerr << "No solution." << std::endl;
	return (EXIT_SUCCESS);
}
