/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:40:56 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 15:55:35 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP__
#define CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat( void ) : Animal()
        {
            this->type = "Cat";
            std::cout << this->type << " default constractor called. " << std::endl;
        };
        
        Cat(const Animal& source)
        {
            std::cout << this->type << " copy constractor called. " << std::endl;
            *this = source;
        }

        Cat& operator=(const Cat& source)
        {
            if (this != &source)
                this->type = source.type;
            return (*this);
        }

        void makeSound( void ) const 
        {
            std::cout << "MEAAWWWWW ....  " << std::endl;
        };

        ~Cat( void )
        {
            std::cout << this->type << " destructor called." << std::endl;
        };
};

#endif