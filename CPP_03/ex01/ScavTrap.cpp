/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:20:50 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/27 16:28:03 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap("")
{
    std::cout << "ScavTrap " << Name << " created using default constractor." << std::endl;
    ClapTrap::Hit_points = 100;
    ClapTrap::Energy_points = 50;
    ClapTrap::Attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string& Name) : ClapTrap(Name)
{
    std::cout << "ScavTrap " << Name << " created." << std::endl;
    ClapTrap::Hit_points = 100;
    ClapTrap::Energy_points = 50;
    ClapTrap::Attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& source) : ClapTrap(source)
{
    std::cout << "ScavTrap " << Name << " created using copy constractor." << std::endl;
}

ScavTrap&
ScavTrap::operator=(const ScavTrap& source)
{
    if (this != &source)
    {
        ClapTrap::Name = source.Name;
        ClapTrap::Hit_points = source.Hit_points;
        ClapTrap::Energy_points = source.Energy_points;
        ClapTrap::Attack_damage = source.Attack_damage;
    }
    return (*this);
}

void
ScavTrap::attack(const std::string& target)
{
    if (Energy_points > 0) 
    {
        std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!." << std::endl;
        Energy_points--;
    } 
    else
        std::cout << "ScavTrap " << Name << " has no energy points left to attack." << std::endl;
}

void
ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode." << std::endl;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "ScavTrap " << Name << "destroyed!" << std::endl;
}
