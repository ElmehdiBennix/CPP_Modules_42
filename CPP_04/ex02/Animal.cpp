/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:59 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 18:24:36 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal( void ) : type("")
{
    std::cout << "AAnimal default Constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& source)
{
    std::cout << "AAnimal copy Constructor called." << std::endl;
    *this = source;
}

AAnimal&
AAnimal::operator=(const AAnimal& source)
{
    if (this != &source)
        this->type = source.type;
    return (*this);
}

void
AAnimal::makeSound( void ) const
{
    std::cout << "No AAnimal type." << std::endl;
}

std::string
AAnimal::getType( void ) const
{
    return (this->type);
}

AAnimal::~AAnimal( void )
{
    std::cout << "AAnimal destructor called." << std::endl;
}
