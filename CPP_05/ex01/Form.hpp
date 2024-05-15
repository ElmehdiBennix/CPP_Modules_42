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
        Form(void) : _name("DEF"), _signator(false), _signatorGrade(0), _executionGrade(0) {
            std::cout << "Default constractor called." << std::endl;
        };

        Form(const std::string& name, const int signatorGrade, const int executionGrade) : _name(name), _signator(false), _signatorGrade(signatorGrade), _executionGrade(executionGrade) {
            std::cout << "Constractor called for Form" << std::endl;
        };

        // test this out after
        Form(const Form& source) : _name(source._name), _signator(source._signator), _signatorGrade(source._signatorGrade), _executionGrade(source._executionGrade) {
            std::cout << "Copy constractor called." << std::endl;
        };

        //#####################################################################
//test this out
        Form& operator=(const Form& source) {
            Form tmp(source);
            return tmp;
        };

        //#####################################################################

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

        //#####################################################################

        void beSigned(const Bureaucrat& obj) {
            if (obj.getGrade() <= _signatorGrade)
                _signator = true;
            throw (GradeTooLowException());
        };

        //#####################################################################

        class GradeTooHighException : public std::exception {
            public :
                const char* what() const throw() {
                    return ("Form Grade is too low");
                };
        };

        class GradeTooLowException : public std::exception {
            public :
              const char* what() const throw() {
                    return ("Form Grade is too low");
                };
        };

        //#####################################################################

        ~Form(void) throw() {
            std::cout << "Destractor called for form." << std::endl;
        };
};
        // void signForm(const Bureaucrat& obj);

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << obj.getName() << " Form : \nGrade to be signed = " << obj.getSignatorGrade() << "\nGrade to be executed = " << obj.getExecutionGrade() << "\nSignator status : " << ((obj.getSignator()) ? "True" : "False");
    return os;
}

#endif