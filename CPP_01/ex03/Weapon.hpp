/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:59 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/06 10:05:54 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_HPP_
#define Weapon_HPP_

#include <iostream>

#define RESET "\033[0m";
#define RED "\033[31m";
#define GREEN "\033[32m";
#define YELLOW "\033[33m";
#define BLUE "\033[34m";

class Weapon
{
    public:
        Weapon(const std::string& _type) : type(_type) {};

        std::string   get_Type(void) ;
        void    set_Type(const std::string& newType);

    private:
        std::string type;
};

#endif
