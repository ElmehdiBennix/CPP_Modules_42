/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:56 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 09:35:12 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& _type) : type(_type) {
    std::cout << "Weapon " << this->type << " :: constructor has been called." << std::endl;
};

const std::string&   
Weapon::get_Type(void) {
    return type;
};

void
Weapon::set_Type(const std::string& newType) {  
   type = newType;
};


Weapon::~Weapon(void) {
    std::cout << "Weapon " << this->type << " :: destructor has been called." << std::endl;
};
