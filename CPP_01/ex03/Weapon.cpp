/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:56 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/06 10:06:02 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string   Weapon::get_Type(void) 
{
    return type;
}

void    Weapon::set_Type(const std::string& newType)
{  
   type = newType;
}
