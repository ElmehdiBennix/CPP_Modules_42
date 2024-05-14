
#ifndef BUREAUCRAT_HPP__
#define BUREAUCRAT_HPP__

#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

//std::uncaught_exceptions() == 0 noexcept is a keyword that can be used in cpp unlike throw() which is a part of a function signator
// The destructor is not being called because when an exception is thrown, the stack unwinds and all local objects in all stack frames are destructed. However, if the exception is thrown in the constructor of an object, the object is not considered fully constructed, so its destructor will not be called.


 

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat(void);
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat &copy);

        // if we init bureau here and threw excep
        Bureaucrat& operator=(const Bureaucrat &source);

        void setGrade(int grade);

        const std::string& getName(void) const ;
        int getGrade(void) const ;

        int increment(void);
        int decrement(void);

        class GradeTooHighException : public std::exception
        {
            public :
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public :
                const char* what() const throw();
        };

        ~Bureaucrat(void);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif