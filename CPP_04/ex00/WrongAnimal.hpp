/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   B: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:18:38 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/14 22:35:05 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP__
#define WRONGANIMAL_HPP__

#include <iostream>

class WrongAnimal {
    public:
       WrongAnimal( void ) : type("") {
            std::cout << "WrongAnimal constractor called. " << std::endl;
       };

        std::string getType() const {
            return this->type;
        };
        
        void makeSound() const {
            std::cout << "No Animal type. " << std::endl;
        };

       ~WrongAnimal( void ) {
            std::cout << "WrongAnimal distractor called. " << std::endl;
       };

    protected:
        std::string type;
};


#endif