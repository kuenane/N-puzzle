// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 09:54:52 by dcojan            #+#    #+#             //
//   Updated: 2015/03/27 15:56:24 by dcojan           ###   ########.fr       //
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
	bool							maparg = false;
	int								generatesize = 0;

	for (int i = 1; i < ac; i++)
	{
		if ((strcmp(av[i], "-v") == 0 || strcmp(av[i], "--verbose") == 0))
			verbose = true;
		else if ((strcmp(av[i], "-h") == 0 || strcmp(av[i], "--help") == 0))
			display_usage();
		else if ((strcmp(av[i], "-d") == 0 || strcmp(av[i], "--distance") == 0))
		{
			i++;
			if (i >= ac)	errorQuit("Error: expect 0 or 2 after -d or --distance.");
			distflag = get_dist_flag(av[i]);
		}
		else if (strcmp(av[i], "-g") == 0 || strcmp(av[i], "-generate") == 0)
		{
			i++;
			if (i >= ac)
				errorQuit("Error: expect number >= 3 after -g or --generate.");
			generatesize = get_generatesize(av[i]);
		}
		else if (generatesize == 0)
		{
			maparg = true;
			map = mapcreator.createMapFromArg(av[i]);
			i++;
		}
		else if (i < ac)
			errorQuit("Error: unexpected argument");
	}
	if (maparg == false)
		map = (generatesize == 0) ? mapcreator.createMapFromStdin() : mapcreator.generateRefMap(generatesize);
	if (!isSolvable(map))
	{
		std::cout << "Map unsolvable !" << std::endl;
		return (0);
	}
	ref =  mapcreator.createRefMap(map.getDim());
	if (npuzzle(map, ref, verbose, distflag))
		std::cout << "Resolu !" << std::endl;
	else
		std::cerr << "No solution." << std::endl;
	return (EXIT_SUCCESS);
}
