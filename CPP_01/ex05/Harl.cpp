/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:22 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 10:41:54 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void 
Harl::complain(std::string level)
{
    int i;

    std::string levels[4] = {"DEBUG","INFO","WARNING","ERROR"};
    void (Harl::*funcptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (i = 0; i < 4 && level != levels[i]; i++);
    if (i == 4) {
        std::cout << "level : " << level << " does not exist ." << std::endl;
        return ;
    }
    (this->*funcptr[i])();
}

void
Harl::debug(void) 
{
    std::cout << "level : DEBUG = ''. " << std::endl;
}

void
Harl::info(void) 
{
    std::cout << "level : INFO = ''. " << std::endl;
}

void
Harl::warning(void) 
{
    std::cout << "level : WARNING = ''. " << std::endl;
}

void 
Harl::error(void)
{
    std::cout << "level : ERROR = ''. " << std::endl;
}
