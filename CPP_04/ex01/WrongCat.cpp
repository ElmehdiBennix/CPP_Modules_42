/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:18:43 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 16:12:28 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << this->type << " default constractor called. " << std::endl;
}

WrongCat::WrongCat(const WrongCat& source)
{
    std::cout << this->type << " copy constractor called. " << std::endl;
    *this = source;
}

WrongCat&
WrongCat::operator=(const WrongCat& source)
{
    if (this != &source)
        this->type = source.type;
    return (*this);
}

void
WrongCat::makeSound( void ) const 
{
    std::cout << "WrongCat sound !!!" << std::endl;
}

WrongCat::~WrongCat( void )
{
    std::cout << this->type << " destructor called." << std::endl;
}
