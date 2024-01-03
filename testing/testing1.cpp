/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing1.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 05:54:07 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/02 02:08:36 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


namespace xxx{
    class leme
    {
        public:
            leme(void):name(""),age(0),death(true){
                std::cout<<"constractor called"<<std::endl;
            };
            leme(std::string num):age(0),death(true){
                std::cout<<"constractor name called "<< x <<std::endl;
                if (num.empty())
                    name = "";
                else
                    name = num;
            };
            // std::string print_name(void){
            //     // std::cout<<name<<std::endl;
            //     return(name);
            // };
            ~leme(void){
                std::cout<< x <<" goneeeeee ..... "<<std::endl;
            };
            int x;
        private:
            int age;
            std::string name;
            bool death;
    };
}


int main(void)
{
    xxx::leme one;
    one.x = 2;
    std::cout<<"set to "<<one.x<<std::endl;
    one = xxx::leme(""); // another class got initilized here and returned to one so 2 dont exist
    std::cout<<"set to "<<one.x<<std::endl;
    one.x = 4;
    std::cout<<"set to "<<one.x<<std::endl;
    // one.print_name();
}