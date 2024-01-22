/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:05:30 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/19 20:22:34 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contacts::Contacts(void) : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("") {};

Contacts::Contacts(std::string& fname, std::string& lname, std::string& nname, std::string& nbr, std::string& secret) : _first_name(fname), _last_name(lname), _nickname(nname), _phone_number(nbr), _darkest_secret(secret) {};

void    Contacts::display(void)
{
    std::cout << " # first name = " << _first_name << std::endl;
    std::cout << " # last name = " << _last_name << std::endl;
    std::cout << " # nickname = " << _nickname << std::endl;
    std::cout << " # phone number = " << _phone_number << std::endl;
    std::cout << " # darkest secret = " << _darkest_secret << std::endl;
}

std::string Contacts::trunc_getter(int argno)
{
    if (argno == 0)
        return (trunc(_first_name));
    else if (argno == 1)
        return (trunc(_last_name));
    else
        return (trunc(_nickname));
}

std::string Contacts::trunc(const std::string& field)
{
    std::string padded = field;
    if (field.length() > 10)
        return (padded.substr(0, 9) + ".");
    else
    {
        for (int i(0); i < (int)(10 - field.length()); i++)
            padded += ' '; 
        return padded;
    }
}

void    exit_prog(int e_n)
{
    std::cout << "\n##################################################" << std::endl;
    std::cout << "   -> Thanks for using the crappy phonebook <-   " << std::endl;
    exit(e_n);
}
