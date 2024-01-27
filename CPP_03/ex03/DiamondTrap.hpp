/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 06:41:15 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/27 21:43:09 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP__
#define DIAMONDTRAP_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap {
    public:
        DiamondTrap( void );
        DiamondTrap(const std::string& _Name);
        DiamondTrap(const DiamondTrap& source);

        DiamondTrap& operator=(const DiamondTrap& source);

        using ScavTrap::attack;
        void whoAmI();

        ~DiamondTrap( void );

    private:
        std::string Name;
};

#endif
