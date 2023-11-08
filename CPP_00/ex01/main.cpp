/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:47:27 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/05 19:28:52 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
    PhoneBook phonebook;
    
    string command;
    std::cout << "      -> Welcome to the crappy phonebook <-      " << std::endl;
    std::cout << "##################################################" << std::endl;

    while (true)
    {
        std::cout << "Enter a command 'ADD' or 'SEARCH' or 'EXIT': ";
        if (!std::getline(std::cin, command) || command == "EXIT")
            exit_prog(0);
        else if (command == "ADD")
            phonebook.add();
        else if (command == "SEARCH")
            phonebook.search();
        else
            std::cout << "-> Invalid command." << std::endl;
    }

    return 0;
}
