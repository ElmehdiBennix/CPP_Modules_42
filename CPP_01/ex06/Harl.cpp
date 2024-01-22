/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:22 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/22 22:09:37 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void
Harl::complain(std::string level)
{
    int i;

    std::string levels[4] = {"DEBUG","INFO","WARNING","ERROR"};
    for (i = 0; i < 4 && level != levels[i]; i++);
    switch (i)
    {
        case 0:
            debug();
            std::cout<<std::endl;
        case 1:
            info();
            std::cout<<std::endl;
        case 2:
            warning();
            std::cout<<std::endl;
        case 3:
            error();
            std::cout<<std::endl;
            break;
        default:
            std::cout << "level : '" << level << "' does not exist." << std::endl;
    }
}

void
Harl::debug(void) 
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << " Message : DEBUG = 'love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !'" << std::endl;
}

void
Harl::info(void) 
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << " Message : INFO = 'think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.'" << std::endl;
}

void
Harl::warning(void) 
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << " Message : WARNING = 'I think I deserve to have some extra bacon for free. I’ve been coming for ears whereas you started working here since last month.'" << std::endl;
}

void 
Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << " Message : ERROR = 'his is unacceptable! I want to speak to the manager now.'" << std::endl;
}
