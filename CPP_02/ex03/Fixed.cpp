/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:58:43 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/08 23:38:21 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed() : Fixed_point(0){}

Fixed::Fixed(const int int_to_fixed) {
    this->Fixed_point = int_to_fixed << Fractional_bits;
}

Fixed::Fixed(const float float_to_fixed) {
    this->Fixed_point = roundf(float_to_fixed * (1 << this->Fractional_bits));
}

Fixed::Fixed(const Fixed &source) {
    *this = source;
}

Fixed&
Fixed::operator=(const Fixed &source) {
    if (this != &source)
    {
        // in the subject they call getrawbits then they change the class value diffrant implementation 
        this->Fixed_point = source.Fixed_point;   
    }
    return *this;
}

void
Fixed::setRawBits(int const raw) {
    this->Fixed_point = raw;
}

int
Fixed::getRawBits(void) const {
    return (this->Fixed_point);
}

int
Fixed::toInt(void) const {
    return (this->Fixed_point >> this->Fractional_bits);
}

float
Fixed::toFloat(void) const {
    return static_cast<float>(this->Fixed_point) / (1 << this->Fractional_bits);
}

Fixed::~Fixed(void) {}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}
