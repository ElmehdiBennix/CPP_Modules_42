/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:43:24 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/27 14:02:26 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP__
# define POINT_HPP__

#include "Fixed.hpp"

class Point {
    public:
        Point( void );
        Point( const float _x , const float _y);
        Point (const Point &source);

        Point& operator=(const Point &source);

        bool operator==(const Point &source) const;

        Fixed get_X(void) const;
        Fixed get_Y(void) const;

        ~Point(void);

    private:
        const Fixed  x;
        const Fixed  y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
