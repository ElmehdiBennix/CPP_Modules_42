/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:43 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/06 09:54:17 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::setWeapon( Weapon& weapon) 
{
    humanWeapon = &weapon;
}

void HumanB::attack() 
{
    if (humanWeapon) {
        std::cout << name << " attacks with their " << humanWeapon->get_Type() << std::endl;
    } else {      
        std::cout << name << " attacks with their bare hands" << std::endl;
    }
}

// HumanB::~HumanB(void)
// {
//     delete humanWeapon;
// }
