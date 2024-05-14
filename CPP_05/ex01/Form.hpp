#ifndef FORM_HPP__
#define FORM_HPP__

// #include <iostream>
#include "Bureaucrat.hpp"

class Form 
{

    private :
        const std::string  _name;
        bool               _signator;
        const int          _signatorGrade; // constant grade required to sign it
        const int          _executionGrade; // constant grade required to execute it.

    public :
        Form(void) : _name("NAN"), _signator(false), _signatorGrade(), _executionGrade() {
            std::cout << "default constractor called" << std::endl;
        };

        Form(const std::string& name) : _name("NAN"), _signator(false), _signatorGrade(), _executionGrade() {
            std::cout << "not so default constractor called" << std::endl;
        };

        // test this out after
        Form(const Form& source) : _name(source._name), _signator(source._signator), _signatorGrade(source._signatorGrade), _executionGrade(source._executionGrade) {
            std::cout << "copy constractor called" << std::endl;
        };

        Form& operator=(const Form& source) {
            Form tmp(source);
            return tmp;
        };

        const std::string&  getName(void) const throw() {
            return _name;
        };

        bool    getSignator(void) const throw() {
            return _signator;
        };

        int     getSignatorGrade(void) const throw() {
            return _signatorGrade;
        };

        int     getExecutionGrade(void) const throw() {
            return _executionGrade;
        };

        void beSigned(const Bureaucrat& obj) {
            if (obj.getGrade >= _signatorGrade)
                _signator = 
        };

        void signForm(const Bureaucrat& obj) {

        };

        ~Form(void) {

        };
};
        // void signForm(const Bureaucrat& obj);

std::ostream& operator<<(std::ostream& os, const Form& ob)
{
    os << "tmp" ;
    return os;
}


#endif