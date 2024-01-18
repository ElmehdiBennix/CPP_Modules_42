/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:05:30 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 10:33:51 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP__
#define CONTACTS_HPP__

#include <iostream>

class Contacts 
{
    public:
        Contacts();
        Contacts(std::string& fname, std::string& lname, std::string& nname, std::string& nbr, std::string& secret);

        void    display(void);
        std::string  trunc_getter(int argno);

    private:
        std::string  _first_name;
        std::string  _last_name;
        std::string  _nickname;
        std::string  _phone_number;
        std::string  _darkest_secret;

        std::string  trunc(const std::string& field);
};

void    exit_prog(int e_n);

#endif