/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:58:43 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 11:00:01 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : Fixed_point(0)
{    
    std::cout<<"Default constractor called"<<std::endl;
}

Fixed::Fixed(const int int_to_fixed)
{
    this->Fixed_point = int_to_fixed << Fractional_bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_to_fixed)
{
    this->Fixed_point = roundf(float_to_fixed * (1 << this->Fractional_bits));
    std::cout << "float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &source)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = source;
}

Fixed&
Fixed::operator=(const Fixed &source)
{
    if (this != &source)
    {
        // in the subject they call getrawbits then they change the class value diffrant implementation 
        std::cout<<"Copy assigment operator called"<<std::endl;
        this->Fixed_point = source.Fixed_point;   
    }
    return *this;
}

void
Fixed::setRawBits(int const raw)
{
    std::cout<<"setRawBits member function called"<<std::endl;
    this->Fixed_point = raw;
}

int
Fixed::getRawBits(void) const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return (this->Fixed_point);
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

Fixed::~Fixed(void)
{
    std::cout<<"Destructor called"<<std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) 
{
    os << obj.toFloat();
    return os;
}
