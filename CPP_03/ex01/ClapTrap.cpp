/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:52:01 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/27 22:02:51 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : Name(""), Hit_points(10), Energy_points(10), Attack_damage(0)
{
    std::cout << "ClapTrap " << Name << " created using default constractor." << std::endl;
}

ClapTrap::ClapTrap(const std::string& _Name) : Name(_Name), Hit_points(10), Energy_points(10), Attack_damage(0)
{
    std::cout << "ClapTrap " << Name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source)
{
    std::cout << "ClapTrap " << Name << " created using copy constactor." << std::endl;
    *this = source;
}

ClapTrap&
ClapTrap::operator=(const ClapTrap& source)
{
    if (this != &source)
    {
        this->Name = source.Name;
        this->Hit_points = source.Hit_points;
        this->Energy_points = source.Energy_points;
        this->Attack_damage = source.Attack_damage;
    }
    return (*this);
}

void
ClapTrap::attack(const std::string& target)
{
    if (Energy_points > 0) 
    {
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!." << std::endl;
        Energy_points--;
    } 
    else
        std::cout << "ClapTrap " << Name << " has no energy points left to attack." << std::endl;
}

void
ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit_points > 0) 
    {
        Hit_points -= amount;
        std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!." << std::endl;
    } 
    else 
        std::cout << "ClapTrap " << Name << " has no hit points left." << std::endl;
}

void
ClapTrap::beRepaired(unsigned int amount)
{
    if (Energy_points > 0) 
    {
        Hit_points += amount;
        std::cout << "ClapTrap " << Name << " is repaired for " << amount << " hit points." << std::endl;
        Energy_points--;
    }
     else 
        std::cout << "ClapTrap " << Name << " has no energy points left to repair." << std::endl;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "ClapTrap " << Name << " destroyed." << std::endl;
}
