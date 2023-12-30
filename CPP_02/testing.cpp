/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:26:14 by ebennix           #+#    #+#             */
/*   Updated: 2023/12/19 21:03:23 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include <iomanip> // Include this library

int stupid_test_uno(void)
{
    
    float x = 0.30000f;
    float y = 0.30000f;


    float comp = x + y;

    std::cout << std::fixed; // Use fixed-point notation
    std::cout << std::setprecision(std::numeric_limits<float>::max_digits10); // Set pre
    
    if (comp == 0.6000000000000000f)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;


    std::cout << "additiong x and y: " << x + y << std::endl;

    return (0);
}

int main(void)
{
    // binary16_t x = 0.30000f;
    float number = 4.015f;
    int integerNumber = static_cast<int>(number); // Convert to integer
    integerNumber = integerNumber >> 1;

    std::cout << "2-number: " << (float)integerNumber << std::endl;
    return 0;
}

// 1-number: 450000000
// 2-number: 4.5e+08