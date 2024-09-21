#ifndef AFORM_HPP__
#define AFORM_HPP__

#include <iostream>

class Bureaucrat;

class AForm
{
    private :
        const std::string  _name;
        bool               _signator;
        const int          _signatorGrade;
        const int          _executionGrade;

    public :
        AForm(void);
        AForm(const std::string& name, const int signatorGrade, const int executionGrade);
        AForm(const AForm& source);

        AForm&                  operator=(const AForm& source);

        const   std::string&    getName(void) const throw();
        bool                    getSignator(void) const throw();
        int                     getSignatorGrade(void) const throw();
        int                     getExecutionGrade(void) const throw();

        void                    beSigned(const Bureaucrat& obj);
        virtual void            execute(const Bureaucrat& executor) const = 0;

        class GradeTooHighException : public std::exception {
            public :
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public :
              const char* what() const throw();
        };

        virtual ~AForm(void);
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
