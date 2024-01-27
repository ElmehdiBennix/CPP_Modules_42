/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:20:53 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/27 14:25:17 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap( void );
        ScavTrap(const std::string& Name);
        ScavTrap(const ScavTrap& source);

        ScavTrap& operator=(const ScavTrap& source);

        void attack(const std::string& target);
        void guardGate( void );

        ~ScavTrap( void );
};

#endif
