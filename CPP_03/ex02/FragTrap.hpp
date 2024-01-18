/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 06:21:58 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/11 06:34:52 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP__
#define FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
    public:
        FragTrap(std::string Name):ClapTrap(Name, 100, 100, 30){
            std::cout<<"FragTrap "<< Name << " is created." << std::endl;
        };

        void highFivesGuys(void){
            std::cout << "FragTrap " << Name << " requests a high five!" << std::endl;
        };

        ~FragTrap( void ){
            std::cout<<"FragTrap "<< Name << " is getting destroyed." << std::endl;
        }; 
};

#endif