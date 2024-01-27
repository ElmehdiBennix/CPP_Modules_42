/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:52:04 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/27 15:42:56 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <iostream>

class ClapTrap
{
    public:
        ClapTrap( void );
        ClapTrap(const std::string& _Name);
        ClapTrap(const ClapTrap& source);

        ClapTrap& operator=(const ClapTrap& source);

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        ~ClapTrap( void );

    protected:
        std::string Name;
        int Hit_points;
        int Energy_points;
        int Attack_damage;
};

#endif
