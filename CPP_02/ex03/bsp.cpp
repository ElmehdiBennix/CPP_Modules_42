/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:43:15 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/09 10:31:06 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed
abs(Fixed x) {
    if (x < 0)
        return x * -1;
    return x;
};

static Fixed 
area(Point const a, Point const b, Point const c) {
    return (abs(a.getX()*b.getY()+b.getX()*c.getY()+c.getX()*a.getY()-a.getX()*c.getY()-b.getX()*a.getY()-c.getX()*b.getY()) / 2);
};

bool
bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed total_area = area(a,b,c);
    Fixed a1 = area(a,b,point);
    Fixed a2 = area(b,c,point);
    Fixed a3 = area(a,c,point);
      return (total_area == a1 + a2 + a3);
};
