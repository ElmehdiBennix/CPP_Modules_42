/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:47:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/11/01 21:34:23 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include <iostream>

#define MAX_CONTACTS 8
#define string std::string

void    exit_prog(int e_n);

class Contacts 
{
    public:
        Contacts(): _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("") {};
        Contacts(string& fname, string& lname, string& nname, string& nbr, string& secret): _first_name(fname), _last_name(lname), _nickname(nname), _phone_number(nbr), _darkest_secret(secret) {};

        void    display(void);
        string trunc_getter(int argno);

    private:
        string _first_name;
        string _last_name;
        string _nickname;
        string _phone_number;
        string _darkest_secret;

        string trunc(const string& field);
};

class PhoneBook
{
    public:
        PhoneBook(void): index(0), total_flag(false) {};

        void    add(void);
        void    search(void);
        
    private:
        int      index;
        bool      total_flag;
        Contacts _contacts[MAX_CONTACTS];

        bool isWhitespaceOrEmpty(const string& str);
        bool isNumeric(const string& str);
        void    get_index(void);
};

#endif