/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:40:58 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 17:30:37 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
    this->type = "Dog";
    std::cout << this->type << " default constractor called. " << std::endl;
}

Dog::Dog(const Dog& source)
{
    std::cout << "Dog copy constractor called. " << std::endl;
    *this = source;
}

Dog& 
Dog::operator=(const Dog& source)
{
    if (this != &source)
        this->type = source.type;
    return (*this);
}

void 
Dog::makeSound( void ) const
{
    std::cout << "EY WHAT DA DOG DOING ?" << std::endl;
}

Dog::~Dog( void )
{
    std::cout << this->type << " destructor called." << std::endl;
}
