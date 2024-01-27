/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 06:41:15 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/27 16:29:06 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP_
#define DIAMONDTRAP_HPP_

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap {
    public:
        DiamondTrap(std::string _Name) : ClapTrap(_Name + "_clap_name"), ScavTrap(_Name), FragTrap(_Name), Name(_Name)
        { 
            FragTrap::Hit_points = 100;
            ScavTrap::Energy_points = 50;
            FragTrap::Attack_damage = 30;
        };

        void attack(const std::string &target)
        {
            ScavTrap::attack(target);
        };

        void whoAmI()
        {
            std::cout<< "am DiamondTrap my name is " << this->Name << std::endl;
            std::cout<< "am ClapTrap my name is " << ClapTrap::Name << std::endl;
        };

        ~DiamondTrap( void )
        {
            std::cout<<"DiamondTrap "<< Name << " is getting destroyed." << std::endl;
        };

    private:
        std::string Name;
};

#endif
