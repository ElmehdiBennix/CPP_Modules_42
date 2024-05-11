
#ifndef BUREAUCRAT_HPP__
#define BUREAUCRAT_HPP__

#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

//std::uncaught_exceptions() == 0 noexcept is a keyword that can be used in cpp unlike throw() which is a part of a function signator

class GradeTooHighException : public std::exception
{
    private :
        std::string _message;

    public :
        GradeTooHighException(const std::string& message);
        const char* what() const throw();
         ~GradeTooHighException() throw();
};
 
class GradeTooLowException : public std::exception
{
    private :
        std::string _message;
    
    public :
        GradeTooLowException(const std::string &message);
        const char* what() const throw();
         ~GradeTooLowException() throw();
};

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

        ~Bureaucrat(void);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif