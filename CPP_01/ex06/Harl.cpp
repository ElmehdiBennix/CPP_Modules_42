/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:22 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/08 01:14:17 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
    int i = 0;
    std::string levels[4] = {"DEBUG","INFO","WARNING","ERROR"};
    for (;i < 4 && level != levels[i]; i++);
    switch (i)
    {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();    
        case 3:
            error();
            break;
        default:
            std::cout << "level : " << level << " does not exist ." << std::endl;
    }
    
    
}

void Harl::debug(void)
{
    std::cout << "level : DEBUG = ''. " << std::endl;
}

void Harl::info(void)
{
    std::cout << "level : INFO = ''. " << std::endl;
}

void Harl::warning(void)
{
    std::cout << "level : WARNING = ''. " << std::endl;
}

void Harl::error(void)
{
    std::cout << "level : ERROR = ''. " << std::endl;
}
