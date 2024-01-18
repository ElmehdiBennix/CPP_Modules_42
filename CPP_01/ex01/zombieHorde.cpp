/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:48:04 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 06:14:28 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N < 0)
        return (NULL);
    Zombie *ptr = new Zombie[N];

    std::cout << "**********************************" << std::endl;

    for (int i = 0; i < N ; i++)
        ptr[i] = Zombie(name, i);

    return (ptr);
}
