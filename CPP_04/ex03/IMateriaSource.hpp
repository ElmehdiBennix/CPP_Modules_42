/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:46:58 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 16:06:06 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP__
#define IMATERIASOURCE_HPP__

#include "Ice.hpp"
#include "Cure.hpp"

class IMateriaSource
{
    public:
        virtual AMateria* createMateria(std::string const & type) = 0;
        virtual void learnMateria(AMateria*) = 0;
        virtual ~IMateriaSource() {};
};

#endif
