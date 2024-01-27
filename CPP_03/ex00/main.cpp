/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:52:06 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/27 22:02:05 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ( void )
{
    {
        ClapTrap test_01("DRACULA");

        for (int i = 0 ; i < 6; i++)
        {
            test_01.attack("HUMAN");
            test_01.beRepaired(5);
        }
    }
    std::cout<<std::endl<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;
    
    ClapTrap test_00("MONSTER");
    
    std::cout<<std::endl<<"-----------------------------------------------" << std::endl;
    test_00.attack("HUMAN");
    std::cout<<"-----------------------------------------------" << std::endl;
    test_00.beRepaired(5);
    std::cout<<"-----------------------------------------------" << std::endl;
    test_00.takeDamage(10);
    std::cout<<"-----------------------------------------------" << std::endl << std::endl;
    
    return 0;
}
