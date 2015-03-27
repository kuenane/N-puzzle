// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   options.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/27 12:36:04 by dcojan            #+#    #+#             //
//   Updated: 2015/03/27 12:38:23 by dcojan           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <n-puzzle.hpp>

void		errorQuit(std::string error)
{
	std::cout << error << std::endl;
	exit(EXIT_FAILURE);
}

void		display_usage()
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

int			get_dist_flag(char *av)
{
	int								distflag = EUCLIDEAN;

	if (strcmp(av, "0") == 0)
		distflag = EUCLIDEAN;
	else if (strcmp(av, "1") == 0)
		distflag = MANHATTAN;
	else if (strcmp(av, "2") == 0)
		distflag = HAMMING;
	else {
		std::cout << "Error: expect 0 to 2 after -d or --distance."<< std::endl;
		exit(EXIT_FAILURE);
	}
	return distflag;
}

int			get_generatesize(char *av)
{
	int								generatesize;

	generatesize = atoi(av);
	if (generatesize < 3)
		errorQuit("Error: expect number >= 3 after -g or --generate.");
	return generatesize;
}
