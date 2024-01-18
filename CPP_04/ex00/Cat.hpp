/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:40:56 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/16 14:40:17 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP__
#define CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat( void ) : Animal() {
            this->type = "Cat";
            std::cout << "Cat constractor called. " << std::endl;
        };

        void makeSound() const {
            std::cout << "MEAAWWWWW ....  " << std::endl;
        };

        ~Cat( void ) {
            std::cout << "Cat distractor called. " << std::endl;
        };
};

#endif