/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:12:31 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 17:37:15 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) 
{
    std::cout << "Brain default constractor called. " << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "turip ip ip turip";
}

Brain::Brain(const std::string& _idea)
{
    std::cout << "Brain constractor called. " << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = _idea;
}

Brain::Brain(const Brain& source)
{
    std::cout << "Brain copy constractor called. " << std::endl;
    *this = source;
}

Brain&
Brain::operator=(const Brain& source)
{
    if (this != &source)
    {
	    std::cout << "Brain Copy assignment operator called." << std::endl;
        for (int i = 0; i < 100; i++)
            this->ideas[i] = source.ideas[i];
    }
    return (*this);
}

Brain::~Brain( void )
{
    std::cout << "Brain destructor called. " << std::endl;
}
