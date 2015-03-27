// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 09:54:52 by dcojan            #+#    #+#             //
//   Updated: 2015/03/27 11:09:47 by dcojan           ###   ########.fr       //
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
	int								generatesize;

	for (int i = 1; i < ac; i++)
	{
		if ((strcmp(av[i], "-v") == 0 || strcmp(av[i], "--verbose") == 0))
			verbose = true;
		else if ((strcmp(av[i], "-h") == 0 || strcmp(av[i], "--help") == 0))
		{
			std::cout << "usage: n_puzzle [-h] [-v] [-d DISTANCE] [-g SIZE]filename\n"
					  << "usage: [stdin] | n_puzzle [-h] [-v] [-d DISTANCE] [-g SIZE]\n\n"
					  << "optional argument:\n"
					  << "  -h, --help\t\t\t\tShow this message and exit.\n"
					  << "  -v, --verbose\t\t\t\tVerbose mode.\n"
					  << "  -d DISTANCE, --distance DISTANCE\tDistance algorithm\n"
					  << "  -g SIZE, --generate SIZE\t\tgenerate a SIZE ref map, SIZE >= 3\n"
					  << "  DISTANCE (default 0):\n\t\t0 for euclidean\n\t\t1 for manhattan\n\t\t2 for hamming\n"
					  << std::endl;
			exit(EXIT_SUCCESS);
		}
		else if ((strcmp(av[i], "-d") == 0 || strcmp(av[i], "--distance") == 0))
		{
			i++;
			if (i >= ac)
			{
				std::cout << "Error: expect 0 or 2 after -d or --distance."<< std::endl;
				exit(EXIT_FAILURE);
			}
			if (strcmp(av[i], "0") == 0)
				distflag = EUCLIDEAN;
			else if (strcmp(av[i], "1") == 0)
				distflag = MANHATTAN;
			else if (strcmp(av[i], "2") == 0)
				distflag = HAMMING;
			else {
				std::cout << "Error: expect 0 to 2 after -d or --distance."<< std::endl;
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(av[i], "-g") == 0 || strcmp(av[i], "-generate") == 0)
		{
			i++;
			if (i >= ac)
			{
				std::cout << "Error: expect number >= 3 after -g or --generate."<< std::endl;
				exit(EXIT_FAILURE);
			}
			generatesize = atoi(av[i]);
			if (generatesize < 3)
			{
				std::cout << "Error: expect number >= 3 after -g or --generate."<< std::endl;
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			maparg = true;
			map = mapcreator.createMapFromArg(av[i]);
			i++;
			if (i < ac)
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
	ref = (generatesize == 0) ? mapcreator.createRefMap(map.getDim()) : mapcreator.generateRefMap(generatesize);

	if (npuzzle(map, ref, verbose, distflag))
		std::cout << "Resolu !" << std::endl;
	else
		std::cerr << "No solution." << std::endl;
	return (EXIT_SUCCESS);
}
