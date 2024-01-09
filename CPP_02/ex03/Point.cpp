/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:43:22 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/09 09:44:56 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : x(0), y(0) {};

Point::Point( const float _x , const float _y): x(_x), y(_y) {};

Point::Point (const Point &obj): x(obj.x), y(obj.y) {};

Point& 
Point::operator=(const Point &source){
    if (this != &source)
    {
        (Fixed) x = source.x;
        (Fixed) y = source.y;
    }
    return (*this);
};

Point::~Point( void ) {};