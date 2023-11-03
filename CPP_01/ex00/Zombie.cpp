/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 04:19:25 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/03 11:26:55 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie(void) : name("UNSET");
{
   
    std::cout << "default constructor has been called for : " << name << " ." << std::endl;
}

Zombie(string& _name)
{
    
    std::cout << "constructor has been called for : " << name << " ." << std::endl;
}
~Zombie(void)
{
    std::cout << "destructor has been called for : " << name << " ." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
