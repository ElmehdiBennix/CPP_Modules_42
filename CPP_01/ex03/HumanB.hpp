/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:48 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 09:28:08 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP_
#define HumanB_HPP_

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
