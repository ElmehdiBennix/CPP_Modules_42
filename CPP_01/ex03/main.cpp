/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 04:19:16 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/04 17:59:12 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int main()
{
    {
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");

        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    
    return 0;
}

// Don’t forget to check for memory leaks.
// In which case do you think it would be best to use a pointer to
// Weapon? And a reference to Weapon? Why? Think about it before
// starting this exercise.
// 9
