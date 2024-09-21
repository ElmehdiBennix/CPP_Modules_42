#ifndef FORM_HPP__
#define FORM_HPP__

#include <iostream>

class Bureaucrat;

class Form
{
    private :
        const std::string  _name;
        bool               _signator;
        const int          _signatorGrade;
        const int          _executionGrade;

    public :
        Form(void);
        Form(const std::string& name, const int signatorGrade, const int executionGrade);
        Form(const Form& source);

        Form&               operator=(const Form& source);

        const std::string&  getName(void) const throw();
        bool                getSignator(void) const throw();
        int                 getSignatorGrade(void) const throw();
        int                 getExecutionGrade(void) const throw();

        void                beSigned(const Bureaucrat& obj);

        class GradeTooHighException : public std::exception {
            public :
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public :
                const char* what() const throw();
        };

        ~Form(void);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
