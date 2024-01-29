/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:40:01 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 19:47:29 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
    std::cout << this->Type << " default constractor called." << std::endl;
}

Ice::Ice(const Ice& source):  AMateria("ice")
{
    std::cout << this->Type << " copy constractor called." << std::endl;
    *this = source;
}

Ice&
Ice::operator=(const Ice& source)
{
    if (this != &source)
        this->Type = source.Type;
    return (*this);
}

void
Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*
Ice::clone() const
{
    return (new Ice());
}

Ice::~Ice() 
{
    std::cout << this->Type << " destructor called." << std::endl;
}