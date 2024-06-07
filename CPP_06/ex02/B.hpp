#if !defined(B_CLASS_HPP__)
#define B_CLASS_HPP__

#include "Base.hpp"

class B : public Base{
    // private:
        /* data */
        // B(/* args */);
    public:
        virtual ~B(void) {
            std::cout << "B Gone." << std::endl;
        };
};

#endif