/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:48 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 10:33:30 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP__
#define HumanB_HPP__

#include "Weapon.hpp"

class HumanB {
    public:
        HumanB(const std::string& _name);

        void setWeapon(Weapon& weapon);
        void attack(void);

        ~HumanB(void);

    private:
        std::string name;
        Weapon   *humanWeapon;
};

#endif
