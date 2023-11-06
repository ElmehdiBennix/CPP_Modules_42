/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:48 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/06 10:02:25 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP_
#define HumanB_HPP_

#include <iostream>
#include "Weapon.hpp"

#define RESET "\033[0m";
#define RED "\033[31m";
#define GREEN "\033[32m";
#define YELLOW "\033[33m";
#define BLUE "\033[34m";

class HumanB {
    public:
        HumanB( std::string _name) : name(_name) , humanWeapon(nullptr) {};
        
        void setWeapon( Weapon& weapon) ;
        void attack() ;

    private:
        std::string name;
        Weapon   *humanWeapon;
};

#endif
