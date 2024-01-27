/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 06:41:28 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/27 21:44:32 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main ( void ) {
    DiamondTrap one("Test");

    std::cout << "   =======> Testing attack method...\n";
    one.attack("enemy");
    std::cout << "   =======> Testing whoAmI method...\n";
    one.whoAmI();
    std::cout << "   =======> finished ...\n";


    return 0;

}