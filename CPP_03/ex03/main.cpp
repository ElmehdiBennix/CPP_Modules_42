/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 06:41:28 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/11 14:09:53 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main ( void ) {
    DiamondTrap one("Test");

    // Test attack method
    std::cout << "   =======> Testing attack method...\n";
    one.attack("enemy");
    one.showdata();
    // Test whoAmI method
    std::cout << "   =======> Testing whoAmI method...\n";
    one.whoAmI();
    std::cout << "   =======> finished ...\n";


    return 0;
    // ClapTrap me("mo7a");
    // ScavTrap you("skert7");
    // FragTrap y("at");
    // me.attack("nigger");
    // you.attack("nigger");
    // y.attack("nigger");
}