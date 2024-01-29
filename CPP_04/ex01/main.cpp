/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:56:04 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 18:18:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
    Animal* j = new Dog();
    Animal* k = new Dog(*(Dog*)(j)); // Use copy constructor

    const Animal* i = new Cat();

    delete i;
    delete k;
    delete j;

    system("leaks Exo_01");

    return 0;
}