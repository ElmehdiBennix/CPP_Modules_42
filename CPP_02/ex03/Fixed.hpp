/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:58:41 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/26 07:54:33 by ebennix          ###   ########.fr       */
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
        Fixed(const Fixed &source);
        
        Fixed& operator=(const Fixed &source);
        
        bool operator>(const Fixed &source) const;
        bool operator<(const Fixed &source) const;
        bool operator>=(const Fixed &source) const;
        bool operator<=(const Fixed &source) const;
        bool operator==(const Fixed &source) const;
        bool operator!=(const Fixed &source) const;

        Fixed operator+(const Fixed &source) const;
        Fixed operator-(const Fixed &source) const;
        Fixed operator*(const Fixed &source) const;
        Fixed operator/(const Fixed &source) const;
;
        Fixed& operator++(void);
        Fixed& operator--(void);
        Fixed  operator++(int);
        Fixed  operator--(int);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
    
        int     toInt(void) const;
        float   toFloat(void) const;

        static Fixed& min(Fixed& F_p_A, Fixed& F_p_B);
        static Fixed& max(Fixed& F_p_A, Fixed& F_p_B);
        static const Fixed& min(const Fixed& F_p_A, const Fixed& F_p_B);
        static const Fixed& max(const Fixed& F_p_A, const Fixed& F_p_B);

        ~Fixed(void);

    private:
        int Fixed_point;
        static const int Fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif