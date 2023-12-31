/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:58:41 by ebennix           #+#    #+#             */
/*   Updated: 2023/12/30 01:06:52 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed(void);
        Fixed(int _Fixed_point);
        Fixed(const Fixed &source);

        Fixed& operator=(const Fixed &source);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);

        ~Fixed(void);

    private:
        int Fixed_point;
        static const int Fractional_bits = 8;
};

#endif