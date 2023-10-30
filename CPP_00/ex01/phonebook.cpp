/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:47:27 by ebennix           #+#    #+#             */
/*   Updated: 2023/10/30 20:51:41 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

class Contacts 
{
    public:

    

    private:

};

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void    add(void);
        void    search(void);
    private:
        int     _index;
        Contact _contacts[8];
};

int main(void)
{
    PhoneBook phonebook;
    std::string command;
    std::cout << "Welcome to the phonebook." << std::endl;
    std::cout << "###############################################" << std::endl;

    while (1)
    {
        std::cout << "Enter a command: ";
        std::cin >> command;
        if (command == "ADD")
            phonebook.add();
        else if (command == "SEARCH")
            phonebook.search();
        else if (command == "EXIT")
        {
            
            std::cout << "Invalid command." << std::endl;
            break ;
        }
        else
            std::cout << "Invalid command." << std::endl;
    }
    return (0);

}