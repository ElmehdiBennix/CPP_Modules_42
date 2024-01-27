/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 06:41:17 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/27 21:45:24 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap("_clap_name"), ScavTrap(), FragTrap(), Name("")
{
    std::cout << "DiamondTrap " << Name << " created using default constractor." << std::endl;
    FragTrap::Hit_points = 100;
    ScavTrap::Energy_points = 50;
    FragTrap::Attack_damage = 30;
}

DiamondTrap::DiamondTrap(const std::string& _Name) : ClapTrap(_Name + "_clap_name"), ScavTrap(), FragTrap(), Name(_Name)
{
    std::cout << "DiamondTrap " << Name << " created." << std::endl;
    FragTrap::Hit_points = 100;
    ScavTrap::Energy_points = 50;
    FragTrap::Attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& source)
{
    std::cout << "DiamondTrap " << Name << " created using copy constractor." << std::endl;
    *this = source;
}

DiamondTrap&
DiamondTrap::operator=(const DiamondTrap& source)
{
    if (this != &source)
    {
        ClapTrap::Name = source.ClapTrap::Name;
        DiamondTrap::Name = source.DiamondTrap::Name;
        this->Hit_points = source.Hit_points;
        this->Energy_points = source.Energy_points;
        this->Attack_damage = source.Attack_damage;
    }
    return (*this);
}

void
DiamondTrap::whoAmI()
{
    std::cout<< "am DiamondTrap my name is " << this->Name << std::endl;
    std::cout<< "am ClapTrap my name is " << ClapTrap::Name << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout<<"DiamondTrap "<< Name << " destroyed." << std::endl;
}
