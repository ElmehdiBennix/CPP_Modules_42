
#ifndef BUREAUCRAT_HPP__
#define BUREAUCRAT_HPP__

#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(std::string &name, int grade);
        Bureaucrat(Bureaucrat &copy);


        

        ~Bureaucrat(void);
};

#endif