/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:38:26 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 16:01:57 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP__
#define AMATERIA_HPP__

#include "iostream"
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string Type;
    
    public:
        AMateria( void );
        AMateria(std::string const & type);
        AMateria(const AMateria& source);

        AMateria&   operator=(const AMateria& source);
        std::string const & getType() const;
        virtual void use(ICharacter& target);
        virtual AMateria* clone() const = 0;

        virtual ~AMateria();
};

#endif
