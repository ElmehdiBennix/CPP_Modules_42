/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:40:54 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 17:30:48 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
    this->type = "Cat";
    std::cout << this->type << " default constractor called. " << std::endl;
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
        this->type = source.type;
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
}
