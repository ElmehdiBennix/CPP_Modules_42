/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:56:04 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/16 15:35:01 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//  Animal is an abstract class and cannot be instantiated. Any class that inherits from Animal must provide an implementation for makeSound, otherwise it will also be an abstract class.

int main()
{
    const Animal* j = new Animal();
    delete j;

    return 0;
}