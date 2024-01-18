/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:27:30 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 10:40:16 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP__
#define ZOMBIE_HPP__

#include <iostream>

#define RESET "\033[0m";
#define RED "\033[31m";
#define GREEN "\033[32m";
#define YELLOW "\033[33m";
#define BLUE "\033[34m";

class Zombie
{
    public:
        Zombie(void);
        Zombie(const std::string& _name);
        
        void announce(void);

        ~Zombie(void);

    private:
        std::string name;
};

void    randomChump(std::string name);
Zombie  *newZombie(std::string name);

#endif
