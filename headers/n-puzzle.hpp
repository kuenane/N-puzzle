// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   n-puzzle.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 10:07:40 by dcojan            #+#    #+#             //
//   Updated: 2015/03/26 09:37:50 by dcojan           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <algorithm>
#include <functional>
#include <locale>

#include <ctime>
#include <cctype>
#include <cstdlib>
#include <iostream>

#include <string>
#include <vector>

#include <Map.hpp>
#include <Node.hpp>

// n-puzzle.cpp
bool				npuzzle(Map map, Map ref, bool verbose,int distflag);

// utils.cpp
std::string			&trim(std::string &s);
bool				presentInVec(std::vector<Node*> v, Map map);
void				printSolution(Node *node, int &count, bool verbose);

// generator.cpp
std::vector<unsigned int>			generator(unsigned int width_size);

//isSolvable.cpp
bool								isSolvable(Map &map);
