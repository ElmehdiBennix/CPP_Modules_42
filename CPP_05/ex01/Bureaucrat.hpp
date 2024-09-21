
#ifndef BUREAUCRAT_HPP__
#define BUREAUCRAT_HPP__

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Form;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat(void);
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat &source);

        Bureaucrat&         operator=(const Bureaucrat &source);

        const std::string&  getName(void) const ;
        int                 getGrade(void) const ;

        int                 increment(void);
        int                 decrement(void);

        void                signForm(Form& obj);

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
