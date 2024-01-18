/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:47:30 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 10:33:55 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP__
#define PHONEBOOK_HPP__

#include <iostream>
#include "Contacts.hpp"

#define RESET "\033[0m";
#define RED "\033[31m";
#define GREEN "\033[32m";
#define YELLOW "\033[33m";
#define BLUE "\033[34m";

#define MAX_CONTACTS 8

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

        bool    isWhitespaceOrEmpty(const std::string& str);
        bool    isNumeric(const std::string& str);
        void    get_index(void);
};

#endif