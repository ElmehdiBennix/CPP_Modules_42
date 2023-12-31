/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:58:41 by ebennix           #+#    #+#             */
/*   Updated: 2023/12/31 05:20:32 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        // constractor
        Fixed(void);
        Fixed(const int int_to_fixed);
        Fixed(const float float_to_fixed);
        Fixed(const Fixed &source); // copy constractor
        
        // copy assig operator
        Fixed& operator=(const Fixed &source);
        
        //comparison operators
        Fixed& operator>(const Fixed &source);
        Fixed& operator<(const Fixed &source);
        Fixed& operator>=(const Fixed &source);
        Fixed& operator<=(const Fixed &source);
        Fixed& operator==(const Fixed &source);
        Fixed& operator!=(const Fixed &source);
        
        //arithmetic operators
        Fixed& operator+(const Fixed &source);
        Fixed& operator-(const Fixed &source);
        Fixed& operator*(const Fixed &source);
        Fixed& operator/(const Fixed &source);

        //increment / decrement operators
        Fixed  operator++(int);
        Fixed& operator++(void);
        Fixed  operator--(int);
        Fixed& operator--(void);

        // memeber functions
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        static Fixed& min(Fixed& F_p_A, Fixed& F_p_B);
        static const Fixed& min(const Fixed& F_p_A, const Fixed& F_p_B);
        static Fixed& max(Fixed& F_p_A, Fixed& F_p_B);
        static const Fixed& max(const Fixed& F_p_A, const Fixed& F_p_B);
    
        //destructor
        ~Fixed(void);

    private:
        // mutable int *nb, * nb; can be modified even if its inside a const method
        int Fixed_point;
        static const int Fractional_bits = 8;
};

// overlaod for the << operator;
std::ostream& operator<<(std::ostream& os, const Fixed& obj); 

#endif