/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:12:31 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 17:11:04 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP__
#define BRAIN_HPP__

#include "iostream"

class Brain
{
    public:
        Brain( void );
        Brain(const std::string& _idea);
        Brain(const Brain& source);

        Brain& operator=(const Brain& source);

        ~Brain( void );

    private:
        std::string ideas[100];
};

#endif