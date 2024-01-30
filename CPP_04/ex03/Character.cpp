/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:44:03 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 15:48:57 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ): name("")
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(std::string const &name): name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}
    

Character::Character(Character const &source)
{
    *this = source;
}
    
Character & 
Character::operator=(Character const &source)
{
    if (this != &source) 
    {
        this->name = source.name;
        for (int i = 0; i < 4; i++) 
        {
            if (inventory[i])
                delete inventory[i];
            inventory[i] = (source.inventory[i]) ? source.inventory[i]->clone() : NULL;
        }
    }
    return *this;
}
    
std::string const & 
Character::getName() const
{
    return name;
}
    
void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
}

void 
Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    inventory[idx] = NULL;
}

void 
Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    inventory[idx]->use(target);
}

 
Character::~Character( void )
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
}
