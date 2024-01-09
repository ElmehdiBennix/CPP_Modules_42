/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:43:24 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/09 10:03:23 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP_
#define POINT_HPP_

#include "Fixed.hpp"

class Point {
    public:
        Point( void );
        Point( const float _x , const float _y);
        Point (const Point &obj);

        Point& operator=(const Point &source);

        Fixed getX() const { return x; }
        Fixed getY() const { return y; }
        ~Point( void );

    private:
        const Fixed  x;
        const Fixed  y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif