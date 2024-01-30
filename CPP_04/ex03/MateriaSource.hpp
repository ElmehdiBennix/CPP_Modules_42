/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:47:10 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 16:04:46 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP__
#define MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    public:
        MateriaSource( void );
        MateriaSource(MateriaSource const & src);
    
        MateriaSource & operator=(MateriaSource const & rhs);
        void learnMateria(AMateria* m);

        AMateria* createMateria(std::string const & type);
        ~MateriaSource( void );

    private:
        AMateria* inventory[4];
};

#endif