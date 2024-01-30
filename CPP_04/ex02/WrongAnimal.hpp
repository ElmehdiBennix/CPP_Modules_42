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

class WrongAnimal
{
    public:
        WrongAnimal( void );
        WrongAnimal(const WrongAnimal& source);

        WrongAnimal& operator=(const WrongAnimal& source);

        void makeSound( void ) const;
        std::string getType( void ) const;

        virtual ~WrongAnimal( void );

    protected:
        std::string type;
};

#endif
