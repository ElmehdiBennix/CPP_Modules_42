/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 04:19:16 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/04 17:54:47 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void leaks(void)
{
    system("leaks BraiiiiiiinnnzzzZ");
}

int main (void)
{
    randomChump("spitter");
    std::cout << "**************************************** " << std::endl;
    randomChump("witch");
    std::cout << "**************************************** " << std::endl;
    Zombie *ptr ;
    ptr = newZombie("clicker");
    ptr->announce();
    delete ptr;
    std::cout << "**************************************** " << std::endl;
    ptr = newZombie("charger");
    ptr->announce();
    delete ptr;
    std::cout << "**************************************** " << std::endl;
    // atexit(leaks);
    return 0;
}

// the destructor is a special member function of a class that is automatically 
//called when an object of that class goes out of scope or is explicitly deleted. You don't
// need to call the destructor manually; it is called automatically by the C++ runtime system. 
//The purpose of the destructor is to perform any necessary cleanup or resource deallocation
// when an object's lifetime ends.