/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:43:06 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/26 08:03:41 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main ( void )
{
    Point   a(0,0);
    Point   b(2,4);
    Point   c(6,0);

    Point   target_0(1,1);
    Point   target_1(6,0);

    std::cout << (bsp(a,b,c,target_0) ? "true: the point is inside the triangle." : "false: the point is not inside the triangle.") << std::endl;
    std::cout << (bsp(a,b,c,target_1) ? "true: the point is inside the triangle." : "false: the point is not inside the triangle.") << std::endl;

    return 0;
}
