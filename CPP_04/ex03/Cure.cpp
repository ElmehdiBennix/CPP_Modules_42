/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:39:26 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 13:09:30 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
    std::cout << this->Type << " default constractor called." << std::endl;
}

Cure::Cure(const Cure& source): AMateria("cure")
{
    std::cout << this->Type << " copy constractor called." << std::endl;
    *this = source;
}

Cure&
Cure::operator=(const Cure& source)
{
    if (this != &source)
        this->Type = source.Type;
    return (*this);
}

void
Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria*
Cure::clone() const
{
    return (new Cure());
}

Cure::~Cure() 
{
    std::cout << this->Type << " destructor called." << std::endl;
}
