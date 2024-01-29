/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:40:54 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 17:34:53 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
    this->type = "Cat";
    std::cout << this->type << " default constractor called. " << std::endl;
    this->head = new Brain();
    // protect i guess
}

Cat::Cat(const std::string& head_ideas)
{
    this->type = "Cat";
    std::cout << this->type << " default constractor called. " << std::endl;
    this->head = new Brain(head_ideas);
    // protect i guess
}

Cat::Cat(const Cat& source)
{
    std::cout << "Cat copy constractor called. " << std::endl;
    *this = source;
}

Cat& 
Cat::operator=(const Cat& source)
{
    if (this != &source)
    {
	    std::cout << "Cat Copy assignment operator called." << std::endl;
        this->type = source.type;
        if (this->head) // test it out
            delete this->head;
        this->head = new Brain(*source.head); // copy values source.head deep copy
    }
    return (*this);
}

void 
Cat::makeSound( void ) const 
{
    std::cout << "MEAAWWWWW ....  " << std::endl;
}

Cat::~Cat( void )
{
    std::cout << this->type << " destructor called." << std::endl;
    delete this->head;
}
