/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:39:32 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 19:49:30 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP__
#define CURE_HPP__

#include "AMateria.hpp"

class Cure: public AMateria 
{
    public:
        Cure();
        Cure(const Cure& source);

        Cure& operator=(const Cure& source);

        virtual void use(ICharacter& target);
        virtual AMateria* clone() const;

        virtual ~Cure();
};

#endif
