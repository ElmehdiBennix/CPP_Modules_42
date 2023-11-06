/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:40 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/06 10:02:58 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_HPP_
#define HumanA_HPP_

#include <iostream>
#include "Weapon.hpp"

#define RESET "\033[0m";
#define RED "\033[31m";
#define GREEN "\033[32m";
#define YELLOW "\033[33m";
#define BLUE "\033[34m";

class HumanA {
    public:
        HumanA( std::string _name, Weapon& weapon) : name(_name), humanWeapon(weapon) {}
        void attack() ;

    private:
        std::string name;
        Weapon& humanWeapon;
};

#endif
