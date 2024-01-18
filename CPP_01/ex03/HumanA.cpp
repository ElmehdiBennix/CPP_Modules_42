/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:38 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 06:15:03 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void
HumanA::attack()  
{
    std::cout << name << " attacks with their " << humanWeapon.get_Type() << std::endl;
}
