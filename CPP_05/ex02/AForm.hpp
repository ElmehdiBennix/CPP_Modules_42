#ifndef AFORM_HPP__
#define AFORM_HPP__

// #include <iostream>
#include "Bureaucrat.hpp"

class AForm 
{
    private :
        const std::string  _name;
        bool               _signator;
        const int          _signatorGrade; // constant grade required to sign it
        const int          _executionGrade; // constant grade required to execute it.

    public :
        AForm(void) : _name("DEF"), _signator(false), _signatorGrade(0), _executionGrade(0) {
            std::cout << "Default constractor called." << std::endl;
        };

        AForm(const std::string& name, const int signatorGrade, const int executionGrade) : _name(name), _signator(false), _signatorGrade(signatorGrade), _executionGrade(executionGrade) {
            std::cout << "Constractor called for Form" << std::endl;
        };

        // test this out after
        AForm(const AForm& source) : _name(source._name), _signator(source._signator), _signatorGrade(source._signatorGrade), _executionGrade(source._executionGrade) {
            std::cout << "Copy constractor called." << std::endl;
        };

        //#####################################################################
//test this out
        AForm& operator=(const AForm& source) {
            AForm tmp(source);
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
                    return ("AForm Grade is too low");
                };
        };

        class GradeTooLowException : public std::exception {
            public :
              const char* what() const throw() {
                    return ("AForm Grade is too low");
                };
        };

        //#####################################################################

        ~AForm(void) throw() {
            std::cout << "Destractor called for form." << std::endl;
        };
};
        // void signForm(const Bureaucrat& obj);

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << obj.getName() << " Form : \nGrade to be signed = " << obj.getSignatorGrade() << "\nGrade to be executed = " << obj.getExecutionGrade() << "\nSignator status : " << ((obj.getSignator()) ? "True" : "False");
    return os;
}

#endif