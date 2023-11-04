/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:27:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/04 12:51:37 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

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
        Zombie(std::string& _name, int i);
        ~Zombie(void);
        
        void announce(void);

    private:
        std::string name;
        int i;
};

Zombie* zombieHorde( int N, std::string name);

#endif
