/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:47:12 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 17:10:11 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) 
{
    std::cout << "MateriaSource Default constractor called." << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
    std::cout << "MateriaSource copy constractor called." << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    *this = src;
}
    
MateriaSource& 
MateriaSource::operator=(MateriaSource const & rhs)
{
    if (this != &rhs) {
        for (int i = 0; i < 4; i++) 
        {
            if (inventory[i])
                delete inventory[i];
            inventory[i] = (rhs.inventory[i]) ? rhs.inventory[i]->clone() : 0;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++) 
    {
        if (!inventory[i]) 
        {
            inventory[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++) {
        if (inventory[i] && inventory[i]->getType() == type)
            return inventory[i]->clone();
    }
    return NULL;
}

MateriaSource::~MateriaSource( void )
{
    for (int i = 0; i < 4; i++)
        if (inventory[i])
            delete inventory[i];
}
