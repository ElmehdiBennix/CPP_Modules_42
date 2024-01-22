/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:43 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/22 14:33:24 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& _name) : name(_name) , humanWeapon(nullptr)
{
    std::cout << "HumanB " << this->name << " :: constructor has been called." << std::endl;
}

void
HumanB::setWeapon(Weapon& weapon)
{
    humanWeapon = &weapon;
}

void
HumanB::attack(void)
{
    if (humanWeapon) {
        std::cout << name << " attacks with " << humanWeapon->get_Type() << std::endl;
    } else {      
        std::cout << name << " attacks with bare hands" << std::endl;
    }
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB " << this->name << " :: destructor has been called." << std::endl;
}
