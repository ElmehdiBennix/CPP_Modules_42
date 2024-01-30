/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:58 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 16:13:05 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP__
#define ANIMAL_HPP__

#include <iostream>

class Animal
{
    public:
        Animal( void );
        Animal(const Animal& source);

        Animal& operator=(const Animal& source);

        virtual void makeSound( void ) const;
        std::string getType( void ) const;

        virtual ~Animal( void );

    protected:
        std::string type;
};

#endif
