/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:43:15 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/26 07:59:53 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed abs(Fixed x)
{
    if (x < 0)
        return x * -1;
    return x;
}

static Fixed area(Point const a, Point const b, Point const c)
{
    return (abs(a.get_X()*b.get_Y()+b.get_X()*c.get_Y()+c.get_X()*a.get_Y()-a.get_X()*c.get_Y()-b.get_X()*a.get_Y()-c.get_X()*b.get_Y()) / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    if (point == a || point == b || point == c) {
        return false;
    }

    Fixed total_area = area(a,b,c);
    Fixed a1 = area(a,b,point);
    Fixed a2 = area(b,c,point);
    Fixed a3 = area(a,c,point);

    if ((a1 == 0 && a2 + a3 == total_area) || 
        (a2 == 0 && a1 + a3 == total_area) || 
        (a3 == 0 && a1 + a2 == total_area)) {
        return false;
    }

    return (total_area == a1 + a2 + a3);
}
