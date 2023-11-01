/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:05:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/01 21:34:23 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void    Contacts::display(void)
{
    std::cout << " # first name = " << _first_name << std::endl;
    std::cout << " # last name = " << _last_name << std::endl;
    std::cout << " # nickname = " << _nickname << std::endl;
    std::cout << " # phone number = " << _phone_number << std::endl;
    std::cout << " # darkest secret = " << _darkest_secret << std::endl;
}

string Contacts::trunc_getter(int argno)
{
    if (argno == 0)
        return (trunc(_first_name));
    else if (argno == 1)
        return (trunc(_last_name));
    else
        return (trunc(_nickname));
}

string Contacts::trunc(const string& field)
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

void    exit_prog(int e_n)
{
    std::cout << "\n##################################################" << std::endl;
    std::cout << "   -> Thanks for using the crappy phonebook <-   " << std::endl;
    exit(e_n);
}