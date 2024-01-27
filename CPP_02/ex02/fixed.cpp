/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:58:43 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/26 07:57:15 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : Fixed_point(0) {}

Fixed::Fixed(const int int_to_fixed) 
{
    this->Fixed_point = int_to_fixed << Fractional_bits;
}

Fixed::Fixed(const float float_to_fixed)
{
    this->Fixed_point = roundf(float_to_fixed * (1 << this->Fractional_bits));
}

Fixed::Fixed(const Fixed &source)
{
    *this = source;
}

Fixed&
Fixed::operator=(const Fixed &source)
{
    if (this != &source)
        this->Fixed_point = source.Fixed_point;   
    return *this;
}

bool
Fixed::operator>(const Fixed &source) const 
{
    return (this->Fixed_point > source.Fixed_point) ? true : false;
}

bool
Fixed::operator<(const Fixed &source) const 
{
    return (this->Fixed_point < source.Fixed_point) ? true : false;
}

bool
Fixed::operator>=(const Fixed &source) const 
{
    return (this->Fixed_point >= source.Fixed_point) ? true : false;
}

bool
Fixed::operator<=(const Fixed &source) const 
{
    return (this->Fixed_point <= source.Fixed_point) ? true : false;
}

bool
Fixed::operator==(const Fixed &source) const 
{
    return (this->Fixed_point == source.Fixed_point) ? true : false;
}

bool
Fixed::operator!=(const Fixed &source) const 
{
    return (this->Fixed_point != source.Fixed_point) ? true : false;
}

Fixed
Fixed::operator+(const Fixed &source) const
{
    return (Fixed(this->toFloat() + source.toFloat()));
}

Fixed
Fixed::operator-(const Fixed &source) const
{
    return (Fixed(this->toFloat() - source.toFloat()));
}

Fixed
Fixed::operator*(const Fixed &source) const
{
    return (Fixed(this->toFloat() * source.toFloat()));
}

Fixed
Fixed::operator/(const Fixed &source) const
{
    return (Fixed(this->toFloat() / source.toFloat()));
}

Fixed&
Fixed::operator++(void)
{
    ++this->Fixed_point;
    return *this;
}

Fixed&
Fixed::operator--(void)
{
    --this->Fixed_point;
    return *this;
}

Fixed 
Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++this->Fixed_point;
    return tmp;
}

Fixed 
Fixed::operator--(int)
{
    Fixed tmp = *this;
    --this->Fixed_point;
    return tmp;
}

int
Fixed::getRawBits(void) const 
{
    return (this->Fixed_point);
}

void
Fixed::setRawBits(int const raw) 
{
    this->Fixed_point = raw;
}

int
Fixed::toInt(void) const
{
    return (this->Fixed_point >> this->Fractional_bits);
}

float
Fixed::toFloat(void) const
{
    return static_cast<float>(this->Fixed_point) / (1 << this->Fractional_bits);
}

Fixed&
Fixed::min(Fixed& F_p_A, Fixed& F_p_B)
{
    return (F_p_A.Fixed_point > F_p_B.Fixed_point)? F_p_B : F_p_A;
}

const Fixed&
Fixed::min(const Fixed& F_p_A, const Fixed& F_p_B)
{
    return (F_p_A.Fixed_point > F_p_B.Fixed_point)? F_p_B : F_p_A;
}

Fixed&
Fixed::max(Fixed& F_p_A, Fixed& F_p_B)
{
    return (F_p_A.Fixed_point > F_p_B.Fixed_point)? F_p_A : F_p_B;
}

const Fixed&
Fixed::max(const Fixed& F_p_A, const Fixed& F_p_B)
{
    return (F_p_A.Fixed_point > F_p_B.Fixed_point)? F_p_A : F_p_B;
}

Fixed::~Fixed(void) {}

std::ostream& operator<<(std::ostream& os, const Fixed& source)
{
    os << source.toFloat();
    return os;
}
