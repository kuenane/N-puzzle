// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MapCreator.class.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 10:10:05 by dcojan            #+#    #+#             //
//   Updated: 2015/03/23 11:54:09 by dcojan           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAPCREATOR_CLASS_HPP
# define MAPCREATOR_CLASS_HPP

# include <n-puzzle.hpp>
# include <fstream>

# include <Map.hpp>
# include <Node.hpp>

class MapCreator {
public:
	MapCreator();
	~MapCreator();
	Map			createMapFromStdin();
	Map			createMapFromArg(std::string arg);

	Map			createRefMap(int size);

private:
	static std::vector<unsigned int>			split_line(std::string line, std::string delimiter, int size);

	MapCreator(MapCreator & mpc);
	MapCreator & operator=(MapCreator & rhs);
};

#endif
