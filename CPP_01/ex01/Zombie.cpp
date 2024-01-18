/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 04:19:25 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 06:14:20 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : name("UNSET"), i(0)
{
    std::cout << "default constructor has been called for : " << name << "/" << i << " ." << std::endl;
}

Zombie::Zombie(std::string& _name, int _i) : name(_name), i(_i)
{
    std::cout << "constructor has been called for : " << name << "/" << i << " ." << std::endl;
}

void
Zombie::announce(void)
{
    std::cout << name << "/" << i << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "destructor has been called for : " << name << "/" << i << " ." << std::endl;
}
