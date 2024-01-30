/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:41:00 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 16:14:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP__
#define DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog( void );
        Dog(const Dog& source);

        Dog& operator=(const Dog& source);

        void makeSound( void ) const;

        ~Dog( void );
};

#endif
