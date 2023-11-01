/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:47:27 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/01 04:38:43 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void    exit_prog(int e_n)
{
    std::cout << "\n##################################################" << std::endl;
    std::cout << "   -> Thanks for using the crappy phonebook <-   " << std::endl;
    exit(e_n);
}

class Contacts 
{
    public:
        Contacts(): _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("") {};
        Contacts(string& fname, string& lname, string& nname, string& nbr, string& secret): _first_name(fname), _last_name(lname), _nickname(nname), _phone_number(nbr), _darkest_secret(secret) {};
        void    display()
        {
            std::cout << " # first name = " << _first_name << std::endl;
            std::cout << " # last name = " << _last_name << std::endl;
            std::cout << " # nickname = " << _nickname << std::endl;
            std::cout << " # phone number = " << _phone_number << std::endl;
            std::cout << " # darkest secret = " << _darkest_secret << std::endl;
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
                return (padded.substr(0, 9) + ".");
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
        PhoneBook(void): index(0), total_flag(false) {};
        void    add(void)
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
        void    search(void)
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
        
    private:
        int      index;
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
};

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
    return (0);

}
// DEFINE COLORS