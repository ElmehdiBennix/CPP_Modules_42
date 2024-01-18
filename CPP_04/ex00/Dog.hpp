/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:41:00 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/16 14:43:44 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP__
#define DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog( void ) : Animal() {
            this->type = "Dog";
            std::cout << "Dog constractor called. " << std::endl;

        };

        void makeSound() const { // we gotta use override 
            std::cout << "EY WHAT DA DOG DOING ?" << std::endl;
        };

        ~Dog( void ) {
            std::cout << "Dog distractor called. " << std::endl;
        };
};

#endif