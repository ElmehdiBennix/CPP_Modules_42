/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:43:24 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 10:57:10 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP__
# define POINT_HPP__

#include "Fixed.hpp"

class Point {
    public:
        Point( void );
        Point( const float _x , const float _y);
        Point (const Point &obj);

        Point& operator=(const Point &source);

        Fixed get_X(void) const { return x; } // calls the copy constractor when i return this using the compiler is optimized for it its called (RVO) or (NRVO) to eliminate the need for the copy.
        Fixed get_Y(void) const { return y; }

        ~Point(void);

    private:
        const Fixed  x;
        const Fixed  y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif