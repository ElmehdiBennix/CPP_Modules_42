/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:59 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 10:37:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_HPP__
#define Weapon_HPP__

#include <iostream>

#define RESET "\033[0m";
#define RED "\033[31m";
#define GREEN "\033[32m";
#define YELLOW "\033[33m";
#define BLUE "\033[34m";

class Weapon
{
    public:
        Weapon(const std::string& _type);

        const std::string&  get_Type(void);
        void                set_Type(const std::string& newType);

        ~Weapon(void);

    private:
        std::string type;
};

#endif
