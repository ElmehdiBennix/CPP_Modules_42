/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:40:56 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 17:38:37 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP__
#define CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    public:
        Cat( void );
        Cat(const std::string& head_ideas);
        Cat(const Cat& source);

        Cat& operator=(const Cat& source);

        void makeSound( void ) const;

        ~Cat( void );

    private:
        Brain *head;
};

#endif
