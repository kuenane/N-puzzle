// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   n-puzzle.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 10:07:40 by dcojan            #+#    #+#             //
//   Updated: 2015/03/24 14:19:12 by dcojan           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <algorithm>
#include <functional>
#include <locale>

#include <cctype>
#include <cstdlib>
#include <iostream>

#include <string>
#include <vector>

#include <Map.hpp>
#include <Node.hpp>

// n-puzzle.cpp
bool				npuzzle(Map map, Map ref);

// utils.cpp
std::string			&trim(std::string &s);
bool				presentInVec(std::vector<Node*> v, Map map);
