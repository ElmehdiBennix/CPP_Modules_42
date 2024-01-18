/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 04:19:25 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 06:13:46 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : name("UNSET")
{
    std::cout << "default constructor has been called for : " << name << " ." << std::endl;
}

Zombie::Zombie(std::string& _name) : name(_name)
{
    std::cout << "constructor has been called for : " << name << " ." << std::endl;
}

void
Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "destructor has been called for : " << name << " ." << std::endl;
}
