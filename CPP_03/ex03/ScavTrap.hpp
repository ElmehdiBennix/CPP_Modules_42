/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:20:53 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/11 14:40:06 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap(std::string Name) : ClapTrap(Name, 100, 50, 20) {
            std::cout << "ScavTrap " << Name << " created." << std::endl;
            std::cout<<"pussy data ===>  "<< Name << " " << Hit_points << " " << Energy_points << " " << Attack_damage << " " << std::endl;
        };
        
        void attack(const std::string& target) {
            if (Energy_points > 0) {
                std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
                Energy_points--;
            } else {
                std::cout << "ScavTrap " << Name << " has no energy points left to attack." << std::endl;
            }
        };

        void guardGate() {
            std::cout << "ScavTrap " << Name << " is now in Gate keeper mode." << std::endl;
        };

        ~ScavTrap() {
            std::cout << "ScavTrap " << Name << " is being destroyed!" << std::endl;
        };
};


#endif
