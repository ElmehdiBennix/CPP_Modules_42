/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:52:01 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/11 04:06:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _Name) : Name(_Name), Hit_points(10), Energy_points(10), Attack_damage(0) {
    std::cout << "ClapTrap " << Name << " created." << std::endl;
};

ClapTrap::ClapTrap(std::string _Name, int _Hit_points, int _Energy_points, int _Attack_damage) : Name(_Name), Hit_points(_Hit_points), Energy_points(_Energy_points), Attack_damage(_Attack_damage) {
    std::cout << "ClapTrap " << Name << " created." << std::endl;
};

void ClapTrap::attack(const std::string& target) {
    if (Energy_points > 0) {
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
        Energy_points--;
    } else {
        std::cout << "ClapTrap " << Name << " has no energy points left to attack." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (Hit_points > 0) {
        Hit_points -= amount;
        std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << Name << " has no hit points left." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (Energy_points > 0) {
        Hit_points += amount;
        std::cout << "ClapTrap " << Name << " is repaired for " << amount << " hit points." << std::endl;
        Energy_points--;
    } else {
        std::cout << "ClapTrap " << Name << " has no energy points left to repair." << std::endl;
    }
}

ClapTrap::~ClapTrap( void ) {
    std::cout << "ClapTrap " << Name << " destroyed." << std::endl;
}