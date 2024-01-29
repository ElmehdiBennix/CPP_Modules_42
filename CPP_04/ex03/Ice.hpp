/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:40:01 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 19:49:26 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP__
#define ICE_HPP__

#include "AMateria.hpp"

class Ice: public AMateria 
{
    public:
        Ice();
        Ice(const Ice& source);

        Ice& operator=(const Ice& source);

        virtual void use(ICharacter& target);
        virtual AMateria* clone() const;

        virtual ~Ice();
};

#endif