/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:38:26 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 04:03:47 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP__
#define AMATERIA_HPP__

#include "iostream"

class AMateria {
    protected:
        std::string type;
    public:
        AMateria(std::string const & type): type(type) {}
        virtual ~AMateria() {}
        std::string const & getType() const {
            return type;
        }
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target) = 0;
};

class Ice: public AMateria {
    public:
        Ice(): AMateria("ice") {}
        virtual ~Ice() {}
    
        virtual AMateria* clone() const {
            return new Ice(*this);
        }
    
        virtual void use(ICharacter& target) {
            std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
        }
};

class Cure: public AMateria {
    public:
        Cure(): AMateria("cure") {}
        virtual ~Cure() {}
    
        virtual AMateria* clone() const {
            return new Cure(*this);
        }
    
        virtual void use(ICharacter& target) {
            std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
        }
};

#endif