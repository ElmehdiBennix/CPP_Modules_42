/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:58 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/16 14:45:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP__
#define ANIMAL_HPP__

#include <iostream>


/*
    Virtual destructor:
    A virtual destructor is used to free up the memory space allocated by 
    the derived class object or instance while deleting instances of the derived
    class using a base class pointer object. A base or parent class destructor
    use the virtual keyword that ensures both base class and the derived class 
    destructor will be called at run time, but it called the derived class first
    and then base class to release the space occupied by both destructors.

    Every destructor down gets called no matter what. virtual makes sure it
    starts at the top instead of the middle.

    Virtual destructors are useful when you might potentially delete an instance 
    of a derived class through a pointer to base class:
*/

class Animal {
    public:
        Animal ( void ) : type("") {
            std::cout << "Animal constractor called. " << std::endl;
        };

        std::string getType() const {
            return this->type;
        };
        
        virtual void makeSound() const {
            std::cout << "No Animal type. " << std::endl;
        };
        
        virtual ~Animal ( void ) {
            std::cout << "Animal distractor called. " << std::endl;
        };

    protected:
        std::string type;
};

#endif