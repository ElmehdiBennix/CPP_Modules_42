/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:41:00 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 15:55:33 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP__
#define DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog( void ) : Animal()
        {
            this->type = "Dog";
            std::cout << this->type << " default constractor called. " << std::endl;
        };

        Dog(const Animal& source)
        {
            std::cout << this->type << " copy constractor called. " << std::endl;
            *this = source;
        }

        Dog& operator=(const Dog& source)
        {
            if (this != &source)
                this->type = source.type;
            return (*this);
        }

        void makeSound( void ) const
        {
            std::cout << "EY WHAT DA DOG DOING ?" << std::endl;
        };

        ~Dog( void )
        {
            std::cout << this->type << " destructor called." << std::endl;
        };
};

#endif