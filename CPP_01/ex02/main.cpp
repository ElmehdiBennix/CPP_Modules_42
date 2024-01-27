/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 04:19:16 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/23 22:00:33 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void )
{
    std::string     myString = "HI THIS IS BRAIN";
    std::string*    stringPTR = &myString;
    std::string&    stringREF = myString;

    std::cout << "-> Memory address of the string variable: " << &myString << std::endl;
    std::cout << "-> Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "-> Memory address held by stringREF: " << &stringREF << std::endl;
    
    std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;

    std::cout << "-> Value of the string variable: " << myString << std::endl;
    std::cout << "-> Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "-> Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}
