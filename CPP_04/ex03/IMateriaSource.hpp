/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:46:58 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/18 04:04:02 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP__
#define IMATERIASOURCE_HPP__

#include "iostream"

class IMateriaSource {
    public:
        virtual AMateria* createMateria(std::string const & type) = 0;
        virtual void learnMateria(AMateria*) = 0;
        virtual ~IMateriaSource() {}
};

class MateriaSource: public IMateriaSource {
    public:
        MateriaSource() {
            for (int i = 0; i < 4; i++)
                inventory[i] = nullptr;
        }

        MateriaSource(MateriaSource const & src) {
            for (int i = 0; i < 4; i++)
                inventory[i] = nullptr;
            *this = src;
        }
    
        MateriaSource & operator=(MateriaSource const & rhs) {
            if (this != &rhs) {
                for (int i = 0; i < 4; i++) {
                    if (inventory[i])
                        delete inventory[i];
                    inventory[i] = rhs.inventory[i] ? rhs.inventory[i]->clone() : 0;
                }
            }
            return *this;
        }

        void learnMateria(AMateria* m) {
            for (int i = 0; i < 4; i++) {
                if (!inventory[i]) {
                    inventory[i] = m->clone();
                    return;
                }
            }
        }

        AMateria* createMateria(std::string const & type) {
            for (int i = 0; i < 4; i++) {
                if (inventory[i] && inventory[i]->getType() == type)
                    return inventory[i]->clone();
            }
            return 0;
        }

        ~MateriaSource() {
            for (int i = 0; i < 4; i++)
                if (inventory[i])
                    delete inventory[i];
        }
    
    private:
        AMateria* inventory[4];
};

#endif