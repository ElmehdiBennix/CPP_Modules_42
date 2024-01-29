/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:58 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 15:49:42 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP__
#define ANIMAL_HPP__

#include <iostream>

class Animal {
    public:
        Animal( void ) : type("")
        {
            std::cout << "Animal default Constructor called." << std::endl;
        }

        Animal(const Animal& source)
        {
            std::cout << "Animal copy Constructor called." << std::endl;
            *this = source;
        }

        Animal& operator=(const Animal& source)
        {
            if (this != &source)
                this->type = source.type;
            return (*this);
        }

        virtual void makeSound( void ) const
        {
            std::cout << "No Animal type. " << std::endl;
        }

        std::string getType( void ) const
        {
            return (this->type);
        }

        virtual ~Animal( void )
        {
            std::cout << "Animal destructor called." << std::endl;
        }

    protected:
        std::string type;
};

#endif
