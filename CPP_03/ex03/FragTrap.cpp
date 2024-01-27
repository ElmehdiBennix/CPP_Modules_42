/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 06:21:56 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/27 21:19:01 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap("")
{
    std::cout << "FragTrap " << Name << " created using default constractor." << std::endl;
    ClapTrap::Hit_points = 100;
    ClapTrap::Energy_points = 100;
    ClapTrap::Attack_damage = 30;
}

FragTrap::FragTrap(const std::string& _Name) : ClapTrap(_Name)
{
    std::cout<<"FragTrap "<< Name << " created." << std::endl;
    ClapTrap::Hit_points = 100;
    ClapTrap::Energy_points = 100;
    ClapTrap::Attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& source)
{
    std::cout << "FragTrap " << Name << " created using copy constractor." << std::endl;
    *this = source;
}

FragTrap&
FragTrap::operator=(const FragTrap& source)
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
FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " requests a high five!" << std::endl;
}

FragTrap::~FragTrap( void )
{
    std::cout<<"FragTrap "<< Name << " destroyed." << std::endl;
}