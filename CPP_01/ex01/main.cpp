/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 04:19:16 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/04 12:59:08 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// void leaks(void)
// {
//     system("leaks Moar_brainz");
// }

int main (void)
{
    int N = 5;
    Zombie *ptr = zombieHorde(N, "el gato");

    std::cout << "**********************************" << std::endl;

    for (int i = 0; i < N; i++)
        ptr[i].announce();
    
    std::cout << "**************************************** " << std::endl;
    
    delete[] ptr;
    // atexit(leaks);
}

// delete is used to free allocated memory using new
// if u wanna clear out an allocated array u have to use delete[]