/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:40:58 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 15:38:01 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
    this->type = "Dog";
    std::cout << this->type << " default constractor called. " << std::endl;
    this->head = new Brain();
    // protect i guess
}

Dog::Dog(const std::string& head_ideas)
{
    this->type = "Dog";
    std::cout << this->type << " default constractor called. " << std::endl;
    this->head = new Brain(head_ideas);
    // protect i guess
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
    {
	    std::cout << "Dog Copy assignment operator called." << std::endl;
        this->type = source.type;
        if (this->head) // test it out
            delete this->head;
        this->head = new Brain(*source.head); // copy values source.head deep copy
    }
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
    delete this->head;
}
