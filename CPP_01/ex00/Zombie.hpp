/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:27:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/03 11:26:42 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <iostream>

class Zombie
{
    public:
        Zombie(void) : name("UNSET")
        {
            std::cout << "default constructor has been called for : " << name << " ." << std::endl;
        };
        Zombie(std::string& _name);
        ~Zombie(void);
        void announce(void);

    private:
        std::string name;
};

void    randomChump(std::string name);
Zombie  *newZombie(std::string name);


#endif