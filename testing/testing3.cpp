/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing3.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 02:09:29 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/02 22:15:31 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

// static int allocations = 0;

// void *myalloc (size_t) { return 0; }
// void * operator new (size_t s) throw() { return myalloc(s); }
// struct Foo {
//     std::string s;
//     Foo () { std::cout << this << std::endl; }
// };

class thang
{
    public:
        thang(void):x(0),str("NAN"),flag(false){
            std::cout<<"default constractor called !"<<std::endl; 
        };
        thang(int x, std::string str, bool flag):x(x),str(str),flag(flag){
            std::cout<<"constractor called !"<<std::endl;
        };
        void print_data(void){
            std::cout<<"ON DATA ===> "<<x<<" , "<<str<<" , "<<flag<<std::endl; 
        };
        void me(void){
            std::cout<<this<<std::endl;
            std::cout<<&(*this)<<std::endl; // so this is a pointer to the class
        };
        void test_ref(const std::string &ref){
            std::cout<<"refff == "<<&ref<<std::endl;
            str = ref;
            std::cout<<"refff str == "<<&str<<std::endl;
        };
        ~thang(void){
            std::cout<<"distractor called"<<std::endl;
        };

    private:
        int x;
        std::string str;
        bool flag;
};

int main()
{
    std::string name = "bruh";
    std::cout<<name<<std::endl;
    thang one(5,"hello",true);
    one.print_data();
    one.me();
    one.test_ref(name);
    one.print_data();
    // std::cout<<allocations<<std::endl;
}