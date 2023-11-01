/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:47:27 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/01 01:31:42 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

class Contacts 
{
    public:
        Contacts(): _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("") {};
        Contacts(string& fname, string& lname, string& nname, string& nbr, string& secret): _first_name(fname), _last_name(lname), _nickname(nname), _phone_number(nbr), _darkest_secret(secret) {};
        string get_arg(int argno)
        {
            if (argno == 0)
                return (_first_name);
            if (argno == 1)
                return (_last_name);
            if (argno == 2)
                return (_nickname);
            if (argno == 3)
                return (_phone_number);
            if (argno == 4)
                return (_darkest_secret);
            else
                return (NULL);
        }
        string trunc_arg(int argno)
        {
            if (argno == 0)
                return (trunc(_first_name));
            if (argno == 1)
                return (trunc(_last_name));
            if (argno == 2)
                return (trunc(_nickname));
            if (argno == 3)
                return (trunc(_phone_number));
            if (argno == 4)
                return (trunc(_darkest_secret));
            else
                return (NULL);
        }

    private:
        string _first_name;
        string _last_name;
        string _nickname;
        string _phone_number;
        string _darkest_secret;
        string trunc(string field)
        {
            if (field.length() > 10)
            {
                return (field.substr(0, 9) + ".");
            }
            else
                return field ;
        }
};

class PhoneBook
{
    public:
        PhoneBook(void): _index(0), total_flag(false) {};
        void    add(void)
        {
            string fields[5] = {"first name : ","first name : " ,"nickname : ", "phone number : ", "darkest secret : "};
            string args[5];
            if (_index == MAX_CONTACTS)
            {
                std::cout << "Phonebook is full replacing the oldest one." << std::endl;
                total_flag = true;
                _index = 0;
            }
            for (int i = 0; i < 5 ;i++)
            {
                std::cout << "enter " << fields[i];
                std::getline(std::cin, args[i]);
                if (args[i].empty()) // parse elements
                {
                    std::cout << "-> invalid field try again ." << std::endl;
                    std::cout << "enter " << fields[i];
                    std::getline(std::cin, args[i]);
                    // if i < 2 only alpha phone nbr only number and + and -
                }
            }
            _contacts[_index] = Contacts(args[0],args[1],args[2],args[3],args[4]);
            _index++;
        }
        void    search(void)
        {   
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << "|   index  |first name| lastname | nickname |" << std::endl;
            for (int i(0); i < MAX_CONTACTS ; i++)
            {
                if (total_flag == false && i == _index)
                    break;
                std::cout << "|" << i << "        |" << _contacts[i].trunc_arg(0) << "|" << _contacts[i].trunc_arg(1) << "|" << _contacts[i].trunc_arg(2) << "|" << std::endl; // problem spaces
            }
            std::cout << "---------------------------------------------" << std::endl;
        }
        
    private:
        int      _index;
        bool      total_flag;
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
        std::getline(std::cin, command);
        if (command == "ADD")
            phonebook.add();
        else if (command == "SEARCH")
            phonebook.search();
        else if (command == "EXIT")
        {
            std::cout << "-> bye bye !!!" << std::endl;
            break ;
        }
        else
            std::cout << "-> Invalid command." << std::endl;
    }
    return (0);

}