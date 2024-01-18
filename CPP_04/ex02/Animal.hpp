/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:58 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/16 15:34:56 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP__
#define ANIMAL_HPP__

#include <iostream>


class Animal {
    public:
        Animal ( void ) : type("") {
            std::cout << "Animal constractor called. " << std::endl;
        };

        std::string getType() const {
            return this->type;
        };

        virtual void makeSound() const = 0;
        
        virtual ~Animal ( void ) {
            std::cout << "Animal distractor called. " << std::endl;
        };

    protected:
        std::string type;
};

#endif