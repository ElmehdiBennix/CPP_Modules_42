/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:52:01 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/10 23:17:57 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _Name) : Name(_Name), Hit_points(10), Energy_points(10), Attack_damage(0) {
    std::cout << "ClapTrap " << Name << " created.\n";
};

void ClapTrap::attack(const std::string& target) {
    if (Energy_points > 0) {
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!\n";
        Energy_points--;
    } else {
        std::cout << "ClapTrap " << Name << " has no energy points left to attack.\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (Hit_points > 0) {
        Hit_points -= amount;
        std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!\n";
    } else {
        std::cout << "ClapTrap " << Name << " has no hit points left.\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (Energy_points > 0) {
        Hit_points += amount;
        std::cout << "ClapTrap " << Name << " is repaired for " << amount << " hit points.\n";
        Energy_points--;
    } else {
        std::cout << "ClapTrap " << Name << " has no energy points left to repair.\n";
    }
}

ClapTrap::~ClapTrap( void ) {
    std::cout << "ClapTrap " << Name << " destroyed." << std::endl;
}