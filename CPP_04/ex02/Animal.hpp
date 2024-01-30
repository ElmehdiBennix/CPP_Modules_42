/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:58 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 15:50:31 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP__
#define ANIMAL_HPP__

#include <iostream>

class AAnimal 
{
    public:
        AAnimal( void );
        AAnimal(const AAnimal& source);

        AAnimal& operator=(const AAnimal& source);

        virtual void makeSound( void ) const = 0;
        std::string getType( void ) const;

        virtual ~AAnimal( void );

    protected:
        std::string type;
};

#endif
