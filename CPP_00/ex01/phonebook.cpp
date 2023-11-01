/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:47:27 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/01 03:43:18 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

class Contacts 
{
    public:
        Contacts(): _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("") {};
        Contacts(string& fname, string& lname, string& nname, string& nbr, string& secret): _first_name(fname), _last_name(lname), _nickname(nname), _phone_number(nbr), _darkest_secret(secret) {};
        void    display()
        {
            std::cout << "first name = " << _first_name << std::endl;
            std::cout << "last name = " << _last_name << std::endl;
            std::cout << "nickname = " << _nickname << std::endl;
            std::cout << "phone number = " << _phone_number << std::endl;
            std::cout << "darkest secret = " << _darkest_secret << std::endl;
        }
        string trunc_getter(int argno)
        {
            if (argno == 0)
                return (trunc(_first_name));
            else if (argno == 1)
                return (trunc(_last_name));
            else
                return (trunc(_nickname));
        }

    private:
        string _first_name;
        string _last_name;
        string _nickname;
        string _phone_number;
        string _darkest_secret;
        string trunc(const string& field)
        {
            string padded = field;
            if (field.length() > 10)
            {
                return (padded.substr(0, 9) + ".");
            }
            else
            {
                for (int i(0); i < (int)(10 - field.length()); i++)
                    padded += ' '; 
                return padded;
            }
        }
};

class PhoneBook
{
    public:
        PhoneBook(void): _index(0), total_flag(false) {};
        void    add(void)
        {
            string fields[5] = {"first name : ", "last name : " ,"nickname : ", "phone number : ", "darkest secret : "};
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
                while (isWhitespaceOrEmpty(args[i]) == true)
                {
                    std::cout << "-> invalid field try again ." << std::endl;
                    std::cout << "enter " << fields[i];
                    std::getline(std::cin, args[i]);
                }
            }
            _contacts[_index] = Contacts(args[0],args[1],args[2],args[3],args[4]);
            _index++;
        }
        void    search(void)
        {   
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << "|index     |first name| lastname | nickname |" << std::endl;
            for (int i(0); i < MAX_CONTACTS ; i++)
            {
                if (total_flag == false && i == _index)
                    break;
                std::cout << "---------------------------------------------" << std::endl;
                std::cout << "|" << i << "         |" << _contacts[i].trunc_getter(0) << "|" << _contacts[i].trunc_getter(1) << "|" << _contacts[i].trunc_getter(2) << "|" << std::endl; // problem spaces
            }
            std::cout << "---------------------------------------------" << std::endl;
            if (total_flag == false && _index == 0)
                return;
            get_index();
        }
        
    private:
        int      _index;
        bool      total_flag;
        Contacts _contacts[MAX_CONTACTS];
        bool isWhitespaceOrEmpty(const string& str) 
        {
            for (int i = 0; str[i]; i++)
            {
                if (!std::isspace(str[i]))
                    return false;
            }
            return true;
        }
        bool isNumeric(const string& str)
        {
            for (int i = 0; str[i]; i++)
            {
                if (!std::isdigit(str[i]))
                    return false;
            }
            return true;  // If all characters are numeric, return true
        }
        void    get_index(void)
        {
            string prompt;
            std::cout << "enter index : ";
            std::getline(std::cin,prompt);
            if (isNumeric(prompt) == false || isWhitespaceOrEmpty(prompt) == true)
            {
                std::cout << "-> Invalid index." << std::endl;
                return;
            }
            int arg = atoi(prompt.c_str());
            if ((total_flag == true && (arg >= 0 && arg < MAX_CONTACTS)) || (total_flag == false && (arg >= 0 && arg < _index)))
                _contacts[arg].display();
            else
                std::cout << "-> Invalid index." << std::endl;
        }
};

int main(void)
{
    PhoneBook phonebook;
    
    string command;
    std::cout << "Welcome to the phonebook." << std::endl;
    std::cout << "###############################################" << std::endl;

    while (true)
    {
        std::cout << "Enter a command 'ADD' or 'SEARCH' or 'EXIT': ";
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
// cntrl d infinite loop