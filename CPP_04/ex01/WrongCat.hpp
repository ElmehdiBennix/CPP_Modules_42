/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:18:47 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 17:11:11 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP__
#define WRONGCAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat( void );
        WrongCat(const WrongCat& source);

        WrongCat& operator=(const WrongCat& source);

        void makeSound( void ) const;

        ~WrongCat( void );
};

#endif
