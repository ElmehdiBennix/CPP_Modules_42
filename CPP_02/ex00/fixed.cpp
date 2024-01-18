/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:58:43 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 11:44:20 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : Fixed_point(0)
{    
    std::cout<<"Default constractor called."<< std::endl;
}

Fixed::Fixed(int _Fixed_point) : Fixed_point(_Fixed_point)
{
    std::cout<<"not so Default constractor called."<< std::endl;
}

Fixed::Fixed(const Fixed &source)
{
    std::cout<<"Copy constructor called."<< std::endl;
    *this = source;
}

Fixed&
Fixed::operator=(const Fixed &source)
{
    if (this != &source)
    {
        // in the subject they call getrawbits then they change the class value diffrant implementation 
        std::cout<<"Copy assigment operator called."<< std::endl;
        this->Fixed_point = source.Fixed_point;
    }
    return *this;
}

void
Fixed::setRawBits(int const raw)
{
    std::cout<<"setRawBits member function called."<< std::endl;
    this->Fixed_point = raw;
}

int
Fixed::getRawBits(void) const
{
    std::cout<<"getRawBits member function called."<< std::endl;
    return (this->Fixed_point);
}

Fixed::~Fixed(void)
{
    std::cout<<"Destructor called."<< std::endl;
}
