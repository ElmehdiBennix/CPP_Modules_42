/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:05:27 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/01 21:35:34 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void    PhoneBook::add(void)
{
    string fields[5] = {"first name : ", "last name : " ,"nickname : ", "phone number : ", "darkest secret : "};
    string args[5];
    if (index == MAX_CONTACTS)
    {
        std::cout << "-> Phonebook is full replacing the oldest one." << std::endl;
        total_flag = true;
        index = 0;
    }
    for (int i = 0; i < 5 ;i++)
    {
        std::cout << "enter " << fields[i];
        if (!std::getline(std::cin, args[i]))
            exit_prog(1);
        while (isWhitespaceOrEmpty(args[i]) == true)
        {
            std::cout << "-> invalid field try again." << std::endl;
            std::cout << "enter " << fields[i];
            if (!std::getline(std::cin, args[i]))
                exit_prog(1);
        }
    }
    _contacts[index] = Contacts(args[0],args[1],args[2],args[3],args[4]);
    index++;
}

void    PhoneBook::search(void)
{   
    if (total_flag == false && index == 0)
    {
        std::cout << "-> phonebook is empty." << std::endl;
        return;
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|Index     |FirstName |LastName  |NickName  |" << std::endl;
    for (int i(0); i < MAX_CONTACTS ; i++)
    {
        if (total_flag == false && i == index)
            break;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "|" << i << "         |" << _contacts[i].trunc_getter(0) << "|" << _contacts[i].trunc_getter(1) << "|" << _contacts[i].trunc_getter(2) << "|" << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
    get_index();
}

bool PhoneBook::isWhitespaceOrEmpty(const string& str) 
{
    for (int i = 0; str[i]; i++)
    {
        if (!std::isspace(str[i]))
            return false;
    }
    return true;
}

bool PhoneBook::isNumeric(const string& str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;  // If all characters are numeric, return true
}

void    PhoneBook::get_index(void)
{
    string prompt;
    std::cout << "enter index : ";
    if (!std::getline(std::cin, prompt))
        exit_prog(2);
    while (isNumeric(prompt) == false || isWhitespaceOrEmpty(prompt) == true)
    {
        std::cout << "-> Invalid index." << std::endl;
        std::cout << "enter index : " << prompt;
        if (!std::getline(std::cin, prompt))
            exit_prog(2);
    }
    
    int arg = atoi(prompt.c_str());
    if ((total_flag == true && (arg >= 0 && arg < MAX_CONTACTS)) || (total_flag == false && (arg >= 0 && arg < index)))
        _contacts[arg].display();
    else
    {
        std::cout << "-> Invalid index." << std::endl;
        get_index();
    }
}
