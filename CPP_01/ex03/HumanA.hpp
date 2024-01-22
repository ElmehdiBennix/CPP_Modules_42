/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:40 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/22 17:11:15 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_HPP__
#define HumanA_HPP__

#include "Weapon.hpp"

class HumanA {
    public:
        HumanA(const std::string& _name, Weapon& weapon);
        
        void attack(void);

        ~HumanA(void);

    private:
        std::string name;
        Weapon& humanWeapon;
};

#endif
