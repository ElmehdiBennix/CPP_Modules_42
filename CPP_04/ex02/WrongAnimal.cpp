/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:18:34 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 16:12:36 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("")
{
    std::cout << "WrongAnimal default Constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& source)
{
    std::cout << "WrongAnimal copy Constructor called." << std::endl;
    *this = source;
}

WrongAnimal&
WrongAnimal::operator=(const WrongAnimal& source)
{
    if (this != &source)
        this->type = source.type;
    return (*this);
}

void
WrongAnimal::makeSound( void ) const
{
    std::cout << "WrongAnimal type." << std::endl;
}

std::string
WrongAnimal::getType( void ) const
{
    return (this->type);
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal destructor called." << std::endl;
}
