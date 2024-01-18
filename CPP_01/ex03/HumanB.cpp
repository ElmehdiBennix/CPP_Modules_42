/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:43 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 09:34:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& _name) : name(_name) , humanWeapon(nullptr)
{
    std::cout << "HumanB " << this->name << " :: constructor has been called." << std::endl;
};

void
HumanB::setWeapon(Weapon& weapon)
{
    humanWeapon = &weapon;
};

void
HumanB::attack(void)
{
    if (humanWeapon) {
        std::cout << name << " attacks with their " << humanWeapon->get_Type() << std::endl;
    } else {      
        std::cout << name << " attacks with their bare hands" << std::endl;
    }
};

HumanB::~HumanB(void)
{
    std::cout << "HumanB " << this->name << " :: destructor has been called." << std::endl;
};
