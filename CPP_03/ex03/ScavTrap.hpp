/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:20:53 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/27 21:19:51 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP__
#define SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap( void );
        ScavTrap(const std::string& _Name);
        ScavTrap(const ScavTrap& source);

        ScavTrap& operator=(const ScavTrap& source);

        void attack(const std::string& target);
        void guardGate( void );

        ~ScavTrap( void );
};

#endif
