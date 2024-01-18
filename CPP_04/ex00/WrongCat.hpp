/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:18:47 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/16 14:43:07 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP__
#define WRONGCAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat() : WrongAnimal() {
            type = "WrongCat";
            std::cout << "WrongCat constractor called. " << std::endl;
        };

        void makeSound() const {
            std::cout << "Meaw ... " << std::endl;
        };

        ~WrongCat() {
            std::cout << "WrongCat distractor called. " << std::endl;
        };
};

#endif