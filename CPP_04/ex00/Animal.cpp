/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:59 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 16:11:47 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("")
{
    std::cout << "Animal default Constructor called." << std::endl;
}

Animal::Animal(const Animal& source)
{
    std::cout << "Animal copy Constructor called." << std::endl;
    *this = source;
}

Animal&
Animal::operator=(const Animal& source)
{
    if (this != &source)
        this->type = source.type;
    return (*this);
}

void
Animal::makeSound( void ) const
{
    std::cout << "No Animal type." << std::endl;
}

std::string
Animal::getType( void ) const
{
    return (this->type);
}

Animal::~Animal( void )
{
    std::cout << "Animal destructor called." << std::endl;
}
