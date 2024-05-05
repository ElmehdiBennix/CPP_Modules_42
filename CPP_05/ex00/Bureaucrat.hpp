
#ifndef BUREAUCRAT_HPP__
#define BUREAUCRAT_HPP__

#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class GradeTooHighException : public std::exception
{
    private :
        std::string _message;

    public :
        GradeTooHighException(const std::string& message) : _message(message) {};
        const char* what() const noexcept {
            return _message.c_str();
        };
};


class GradeTooLowException : public std::exception
{
    private :
        std::string _message;
    
    public :
        GradeTooLowException(const std::string &message) : _message(message) {};
        const char* what() const noexcept {
            return _message.c_str();
        };
};

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat(void) : _name("default"), _grade(150)
        {
            std::cout << "default constractor has been called" << std::endl;
        };

        Bureaucrat(const std::string& name, int grade) : _name(name)
        {
            std::cout << "not the constractor has been called" << std::endl;
            if (grade < HIGHEST_GRADE)
                throw GradeTooHighException("Bureaucrat::GradeTooHighException");
            else if (grade > LOWEST_GRADE)
                throw GradeTooLowException("Bureaucrat::GradeTooLowException");
            this->_grade = grade;
        };

        Bureaucrat(const Bureaucrat &copy)
        {
            *this = copy;
            std::cout << "copy constractor has been called" << std::endl;
        };

            // if we init bureau here and threw excep
        Bureaucrat& operator=(const Bureaucrat &source) 
        {
            if (this != &source)
            {
                (std::string)this->_name = source._name;
                this->_grade = source._grade;
            }
            return (*this);
        }

        const std::string& getName(void) const 
        {
            return _name;
        };

        int getGrade(void) const 
        {
            return _grade;
        };

        void setGrade(int grade)
        {
            if (grade < HIGHEST_GRADE)
                throw GradeTooHighException("Bureaucrat::GradeTooHighException");
            else if (grade > LOWEST_GRADE)
                throw GradeTooLowException("Bureaucrat::GradeTooLowException");
            this->_grade = grade;
        };

        int increment(void)
        {
            if (_grade == HIGHEST_GRADE)
                throw GradeTooHighException("Bureaucrat::GradeTooHighException");
            --_grade;
            return _grade;
        };

        int decrement(void)
        {
            if (_grade == LOWEST_GRADE)
                throw GradeTooLowException("Bureaucrat::GradeTooLowException");
            ++_grade;
            return _grade;
        };

        ~Bureaucrat(void)
        {
            std::cout << "distractor has benn called" << std::endl;
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}

#endif