/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:47:27 by ebennix           #+#    #+#             */
/*   Updated: 2023/10/31 01:24:18 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

class Contacts 
{
    public:
        Contacts(): _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("") {};
        Contacts(string fname, string lname, string nname, string nbr, string secret): _first_name(fname), _last_name(lname), _nickname(nname), _phone_number(nbr), _darkest_secret(secret) {};

    private:
        string _first_name;
        string _last_name;
        string _nickname;
        string _phone_number;
        string _darkest_secret;
};

class PhoneBook
{
    public:
        PhoneBook(void):  {};
        // ~PhoneBook(void);
        void    add(void)
        {
            string args[5] = {"first name","first name" ,"", "", ""} 
            if (_index < 8)
            {
                std::cout << "Enter first name: ";
                std::cin >> _contacts[_index]._first_name;
                std::cout << "Enter first name ";
                std::cin >> _contacts[_index]._last_name;
                std::cout << "Enter nickname: ";
                std::cin >> _contacts[_index]._nickname;
                std::cout << "Enter phone number: ";
                std::cin >> _contacts[_index]._phone_number;
                std::cout << "Enter darkest secret: ";
                std::cin >> _contacts[_index]._darkest_secret;
                _index++;
            }
            else
                std::cout << "Phonebook is full." << std::endl;
        }
        void    search(void);
        
    private:
        
        int     _index;
        Contacts _contacts[MAX_CONTACTS];
};

int main(void)
{
    PhoneBook phonebook;
    
    string command;
    std::cout << "Welcome to the phonebook." << std::endl;
    std::cout << "###############################################" << std::endl;

    while (true)
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