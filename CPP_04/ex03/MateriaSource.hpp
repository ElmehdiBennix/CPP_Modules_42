/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:47:10 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 13:20:45 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP__
#define MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    public:
        MateriaSource() 
        {
            std::cout << "MateriaSource Default constractor called." << std::endl;
            for (int i = 0; i < 4; i++)
                inventory[i] = nullptr;
        }

        MateriaSource(MateriaSource const & src)
        {
            std::cout << "MateriaSource copy constractor called." << std::endl;
            for (int i = 0; i < 4; i++)
                inventory[i] = nullptr;
            *this = src;
        }
    
        MateriaSource & operator=(MateriaSource const & rhs)
        {
            if (this != &rhs) {
                for (int i = 0; i < 4; i++) {
                    if (inventory[i])
                        delete inventory[i];
                    inventory[i] = rhs.inventory[i] ? rhs.inventory[i]->clone() : 0;
                }
            }
            return *this;
        }

        void learnMateria(AMateria* m) // print msg cant have thew obj
        {
            for (int i = 0; i < 4; i++) 
            {
                if (!inventory[i]) 
                {
                    inventory[i] = m->clone();
                    return;
                }
            }
        }

        AMateria* createMateria(std::string const & type)
        {
            for (int i = 0; i < 4; i++) {
                if (inventory[i] && inventory[i]->getType() == type)
                    return inventory[i]->clone();
            }
            return 0;
        }

        ~MateriaSource()
        {
            for (int i = 0; i < 4; i++)
                if (inventory[i])
                    delete inventory[i];
        }
    
    private:
        AMateria* inventory[4];
};

#endif