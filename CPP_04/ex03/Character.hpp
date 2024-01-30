/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:44:01 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 16:07:25 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP__
#define CHARACTER_HPP__

#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character : public ICharacter
{
    public:
        Character( void );
        Character(std::string const &name);
        Character(Character const &source);

        Character & operator=(Character const &source);
    
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

        virtual ~Character( void );

    private:
        std::string name;
        AMateria* inventory[4];
};

#endif
