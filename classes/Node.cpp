// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Node.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 14:15:22 by dcojan            #+#    #+#             //
//   Updated: 2015/03/24 16:11:57 by dcojan           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <Node.hpp>

Node::Node(void){
	return ;
}

Node::~Node(void){
	return ;
}

Node::Node(Node const &copy){
	*this = copy;
}

Node 				&Node::operator=(Node const &rhs){
	_parent = rhs.getParent();
	_map = rhs.getMap();
	_distanceTo = rhs.getDistanceTo();
	return (*this);
}

Node::Node(Map map)
{
	_parent = NULL;
	_map = map;
}

Node				*Node::getParent(void) const{
	return _parent;
}

void				Node::setParent(Node *parent){
	_parent = parent;
}

Map					Node::getMap(void) const{
	return _map;
}

void				Node::setMap(Map map){
	_map = map;
}

double				Node::getDistanceFrom(void) const{
	return _distanceFrom;
}

void				Node::setDistanceFrom(double distance){
	_distanceFrom = distance;
}

double				Node::getDistanceTo(void) const{
	return _distanceTo;
}

void				Node::setDistanceTo(double distance){
	_distanceTo = distance;
}

// void				Node::updateEuclideanDistance(Map &ref, Node &old, e_swap i)
// {
// 	if (i == LEFT)
// 	{
// 	}
// 	else if (i == RIGHT)
// 	{
// 	}
// 	else if (i == UP)
// 	{
// 	}
// 	else
// 	{
// 	}
// }
