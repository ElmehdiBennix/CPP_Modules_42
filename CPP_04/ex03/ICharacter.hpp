/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:43:54 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 21:31:44 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP__
#define ICHARACTER_HPP__

#include "iostream"

class ICharacter
{
    public:
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
    
        virtual ~ICharacter() {}
};

class Character : public ICharacter {
    public:
        Character( void ): name("")
        {
            for (int i = 0; i < 4; i++)
                inventory[i] = nullptr;
        }

        Character(std::string const &name): name(name)
        {
            for (int i = 0; i < 4; i++)
                inventory[i] = nullptr;
        }
    
        Character(Character const &source)
        {
            *this = source;
        }
    
        Character & operator=(Character const &source)
        {
            if (this != &source) 
            {
                this->name = source.name;
                for (int i = 0; i < 4; i++) 
                {
                    if (inventory[i])
                        delete inventory[i];
                    inventory[i] = (source.inventory[i]) ? source.inventory[i]->clone() : nullptr;
                }
            }
            return *this;
        }
    
        virtual std::string const & getName() const
        {
            return name;
        }
    
        virtual void equip(AMateria* m)
        {
            for (int i = 0; i < 4; i++)
            {
                if (!inventory[i])
                {
                    inventory[i] = m;
                    return;
                }
            }
        }
    
        virtual void unequip(int idx)
        {
            if (idx < 0 || idx >= 4 || !inventory[idx])
                return;
            inventory[idx] = nullptr;
        }
    
        virtual void use(int idx, ICharacter& target)
        {
            if (idx < 0 || idx >= 4 || !inventory[idx])
                return;
            inventory[idx]->use(target);
            inventory[idx] = nullptr;
        }

        virtual ~Character()
        {
            for (int i = 0; i < 4; i++)
                if (inventory[i])
                    delete inventory[i];
        }
    
    private:
        std::string name;
        AMateria* inventory[4];
};

#endif
