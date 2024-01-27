/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:43:22 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/27 14:03:31 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : x(0), y(0) {};

Point::Point( const float _x , const float _y): x(_x), y(_y) {};

Point::Point (const Point &source): x(source.x), y(source.y) {};

Point& 
Point::operator=(const Point &source)
{
    if (this != &source)
    {
        *((Fixed*)(&x))= source.x;
        *((Fixed*)(&y)) = source.y;
    }
    return (*this);
}

Fixed
Point::get_X(void) const
{
    return x;
}

Fixed
Point::get_Y(void) const
{
    return y;
}

bool
Point::operator==(const Point &source) const
{
    return ((x == source.x && y == source.y) ? true : false );
}

Point::~Point( void ) {};
