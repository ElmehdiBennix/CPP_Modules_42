/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:56:04 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 16:19:05 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
    AAnimal* j = new Dog();
    AAnimal* k = new Dog(*(Dog*)(j));

    const AAnimal* i = new Cat();

    delete i;
    delete k;
    delete j;

    return 0;
}