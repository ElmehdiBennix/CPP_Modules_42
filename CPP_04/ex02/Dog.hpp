/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:41:00 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 18:25:21 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP__
#define DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
    public:
        Dog( void );
        Dog(const std::string& head_ideas);
        Dog(const Dog& source);

        Dog& operator=(const Dog& source);

        void makeSound( void ) const;

        ~Dog( void );

    private:
        Brain *head;
};

#endif
