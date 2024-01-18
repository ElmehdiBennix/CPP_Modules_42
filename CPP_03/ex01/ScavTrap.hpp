/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:20:53 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/11 06:17:58 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap(std::string Name) : ClapTrap(Name, 100, 50, 20) {
            std::cout << "ScavTrap " << Name << " created." << std::endl;
        };

        void guardGate() {
            std::cout << "ScavTrap " << Name << " is now in Gate keeper mode." << std::endl;
        };

        ~ScavTrap() {
            std::cout << "ScavTrap " << Name << " is being destroyed!" << std::endl;
        };
};


#endif
