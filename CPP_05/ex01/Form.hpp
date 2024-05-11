#ifndef FORM_HPP__
#define FORM_HPP__

// #include <iostream>
#include "Bureaucrat.hpp"

class Form 
{

    private :
        const std::string _name;
        bool    _signator;
        const int  _signatorGrade;
        const int  _executionGrade;

    public :
        Form(void);
        Form(const std::string& name);
        Form(const Form& source);
        Form& operator=(const Form& source);

        const std::string&  getName(void) const;
        bool                getSignator(void) const;
        int                 getSignatorGrade(void) const;
        int                 getExecutionGrade(void) const;

        void beSigned(const Bureaucrat& obj);
        void signForm(const Bureaucrat& obj);


        ~Form(void);
};
        // void signForm(const Bureaucrat& obj);

std::ostream& operator<<(std::ostream& os, const Form& ob)
{
    os << "tmp" ;
    return os;
}


#endif