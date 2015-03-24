// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   utils.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 10:01:14 by dcojan            #+#    #+#             //
//   Updated: 2015/03/24 14:19:35 by dcojan           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <n-puzzle.hpp>

bool						isStringBlank(const char *s)
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (!isblank((int)s[i]))
			return (false);
	}
	return (true);
}

// trim from start
std::string &ltrim(std::string &s)
{
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
std::string &rtrim(std::string &s)
{
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
std::string &trim(std::string &s)
{
        return ltrim(rtrim(s));
}

bool						presentInVec(std::vector<Node*> v, Map map)
{
	Node *el;
	for (std::vector<Node*>::iterator it=v.begin(); it!=v.end(); ++it)
	{
		el = *it;
		if (el->getMap().getHash() == map.getHash())
			return (true);
	}
	return (false);
}
