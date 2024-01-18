/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:52:04 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/11 06:13:26 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <iostream>

class ClapTrap {
    public:
        ClapTrap(std::string _Name);
        ClapTrap(std::string _Name, int _Hit_points, int _Energy_points, int _Attack_damage);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        ~ClapTrap(void);
    protected:
        std::string Name;
        int Hit_points;
        int Energy_points;
        int Attack_damage;

};

#endif