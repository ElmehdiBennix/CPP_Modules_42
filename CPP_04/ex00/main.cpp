/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:37:03 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 13:26:24 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
    {    
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
    
        delete meta;
        delete i;
        delete j;
    }    
    std::cout << "___________________________________________________________\n" << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* j = new WrongCat();

        std::cout << j->getType() << " " << std::endl;
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
    }

    return 0;
}
