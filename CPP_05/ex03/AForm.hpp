#ifndef AFORM_HPP__
#define AFORM_HPP__

#include <iostream>

class Bureaucrat;

class AForm 
{
    private :
        const std::string  _name;
        bool               _signator;
        const int          _signatorGrade; // constant grade required to sign it
        const int          _executionGrade; // constant grade required to execute it.

    public :
        AForm(void);
        AForm(const std::string& name, const int signatorGrade, const int executionGrade);
    // test this out after
        AForm(const AForm& source);
        
        //#####################################################################
    
    //test this out
        // AForm& operator=(const AForm& source);

        //#####################################################################

        const   std::string&    getName(void) const throw();
        bool    getSignator(void) const throw();
        int     getSignatorGrade(void) const throw();
        int     getExecutionGrade(void) const throw();
        
        //#####################################################################

        void beSigned(Bureaucrat& obj);

        //#####################################################################

        virtual void execute(const Bureaucrat& executor) const = 0;

        //#####################################################################

        class GradeTooHighException : public std::exception {
            public :
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public :
              const char* what() const throw();
        };

        //#####################################################################

        virtual ~AForm(void);
};
        // void signForm(const Bureaucrat& obj);

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif