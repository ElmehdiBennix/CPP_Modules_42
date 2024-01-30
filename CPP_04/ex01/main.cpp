/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:56:04 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/30 16:35:48 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define MAX 20

int main( void )
{
    Animal *obj[MAX];

    for (int i = 0; i < MAX; i++)
    {
        if (i < (MAX/2))
            obj[i] = new Dog();
        else
            obj[i] = new Cat();        
    }

    for (int i = 0; i < MAX; i++)
        delete obj[i];

    return 0;
}