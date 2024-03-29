/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:38:29 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 16:07:53 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : Type("")
{
    std::cout << "AMateria " << this->Type << " Default constractor called." << std::endl;
}

AMateria::AMateria(std::string const & type) : Type(type)
{
    std::cout << "AMateria " << this->Type << " constractor called." << std::endl;
}

AMateria::AMateria(const AMateria& source)
{
    std::cout << "AMateria " << this->Type << " copy constractor called." << std::endl;
    *this = source;
}

AMateria&
AMateria::operator=(const AMateria& source)
{
    if (this != &source)
        this->Type = source.Type;
    return (*this);    
}

std::string const & 
AMateria::getType( void ) const
{
    return (this->Type);
}

void
AMateria::use(ICharacter& target)
{
    (void) target;
    std::cout << "Unknown Materia." << std::endl;
}

AMateria::~AMateria( void )
{
    std::cout << "AMateria " << this->Type << " destructor called." << std::endl;
}