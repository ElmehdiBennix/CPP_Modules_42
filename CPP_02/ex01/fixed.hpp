/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:58:41 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 10:32:37 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP__
# define FIXED_HPP__

#include <iostream>
#include <cmath>

#define RESET "\033[0m";
#define RED "\033[31m";
#define GREEN "\033[32m";
#define YELLOW "\033[33m";
#define BLUE "\033[34m";

class Fixed
{
    public:
        Fixed(void);
        Fixed(const int int_to_fixed);
        Fixed(const float float_to_fixed);
        Fixed(const Fixed &source); // copy constractor
    
        Fixed& operator=(const Fixed &source); // copy assig operator

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
    
        ~Fixed(void);

        int Fixed_point;
    private:
        static const int Fractional_bits = 8;
};

// overlaod for the << operator;
std::ostream& operator<<(std::ostream& os, const Fixed& obj); 

#endif