/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing0.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:26:14 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/29 05:12:09 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>

// testing the static data type in classes

// if we want to make aclass static as in static funting in c meaning it only linkes to the current file
// use namespace 
//}
    //class blud{ 
    //}
//}

namespace ss{
    class blud
    {
        public:
            blud(void):x(0){
                nemra = 9;
                std::cout<<"constoctur called"<<std::endl;
            };
            void change_data(int _x, int _nemra)
            {
                x = _x;  
                nemra = _nemra;
            };
            
            void print_data(void) const
            {
                std::cout<<"this is x = "<< x <<std::endl;
                std::cout<<"this is nemra = "<< nemra <<std::endl;
            };
            ~blud(void)
            {
                std::cout<<"destrocture called"<<std::endl;
            };
            
        private:
            int x;
            static int nemra;
    };
}

int blud::nemra = 0;

int main(void)
{
    blud one;
    blud two;
    one.print_data();
    one.change_data(2,4); // static variable changes in all instances of the object blud 
    one.print_data();
    std::cout<<"___________________________________"<<std::endl;
    two.print_data();
}

