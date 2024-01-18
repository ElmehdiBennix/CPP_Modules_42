/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:40:56 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/16 15:20:43 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP__
#define CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    public:
        Cat( void ) : Animal() {
            this->type = "Cat";
            std::cout << "Cat constractor called. " << std::endl;
            this->head = new Brain();
        };

        void makeSound() const {
            std::cout << "MEAAWWWWW ....  " << std::endl;
        };

        ~Cat( void ) {
            std::cout << "Cat distractor called. " << std::endl;
            delete this->head;
        };

        private:
            Brain *head;
};

#endif