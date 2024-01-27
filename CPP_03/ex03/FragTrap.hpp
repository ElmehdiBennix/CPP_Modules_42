/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 06:21:58 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/27 16:14:05 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP__
#define FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap( void );
        FragTrap(const std::string& Name);
        FragTrap(const FragTrap& source);

        FragTrap& operator=(const FragTrap& source);

        void highFivesGuys(void);

        ~FragTrap( void );
};

#endif
