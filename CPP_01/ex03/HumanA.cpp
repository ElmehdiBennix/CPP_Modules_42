/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:38 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 10:14:19 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& _name, Weapon& weapon) : name(_name), humanWeapon(weapon) 
{
    std::cout << "HumanA " << this->name << " :: constructor has been called." << std::endl;
}

void
HumanA::attack(void) 
{
    std::cout << name << " attacks with their " << humanWeapon.get_Type() << std::endl;
}

HumanA::~HumanA(void) 
{
    std::cout << "HumanA " << this->name << " :: destructor has been called." << std::endl;
}
