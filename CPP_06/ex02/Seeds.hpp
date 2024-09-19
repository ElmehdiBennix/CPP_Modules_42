#if !defined(SEEDS_HPP__)
#define SEEDS_HPP__

#include <iostream>
#include <cstdlib>

#define A_CLASS     0
#define B_CLASS     1
#define C_CLASS     2

class Base
{
    public:
        virtual ~Base(void){};
};

class A : public Base
{
    public:
        ~A(void){};
};

class B : public Base
{
    public:
        ~B(void){};
};

class C : public Base
{
    public:
        ~C(void){};
};

#endif
