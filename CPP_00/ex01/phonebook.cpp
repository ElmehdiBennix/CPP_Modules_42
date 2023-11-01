/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:47:27 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/01 03:16:03 by ebennix          ###   ########.fr       */
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
                if (isWhitespaceOrEmpty(args[i]) == true) // parse elements sends the iter number and it parses it depending on condtions of each field
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
            std::cout << "|index     |first name| lastname | nickname |" << std::endl;
            for (int i(0); i < MAX_CONTACTS ; i++)
            {
                if (total_flag == false && i == _index)
                    break;
                std::cout << "---------------------------------------------" << std::endl;
                std::cout << "|" << i << "         |" << _contacts[i].trunc_arg(0) << "|" << _contacts[i].trunc_arg(1) << "|" << _contacts[i].trunc_arg(2) << "|" << std::endl; // problem spaces
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
        void    get_index(void)
        {
            string prompt;
            std::cout << "enter index : ";
            std::getline(std::cin,prompt);
            // PARSE THIS DATA if there is characters in it FAIL IT HIR
            if (isNumeric(prompt) == false || isWhitespaceOrEmpty(prompt) == true)
            {
                std::cout << "Invalid" << std::endl;
                return;
            }
            int arg = atoi(prompt.c_str());
            if ((total_flag == true && (arg >= 0 && arg < MAX_CONTACTS)) || (total_flag == false && (arg >= 0 && arg < _index)))
                display(arg);
            else
                std::cout << "Invalid" << std::endl;
        }
        void    display(int arg) // gotta go public in contacs
        {
            string fields[5] = {"first name = ", "last name = " ,"nickname = ", "phone number = ", "darkest secret = "};
            for (int i(0); i < 5; i++)
                std::cout << fields[i] << _contacts[arg].get_arg(i) << std::endl;
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
        bool isWhitespaceOrEmpty(const string& str) 
        {
            for (int i = 0; str[i]; i++)
            {
                if (!std::isspace(str[i]))
                    return false;
            }
            return true;
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
// cntrl d infinite loop