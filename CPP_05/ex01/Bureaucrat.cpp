#include "Bureaucrat.hpp"

//#####################

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Bureaucrat Grade is too high");
};

//#####################

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Bureaucrat Grade is too low");
};

//#####################

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
    std::cout << "default constractor has been called" << std::endl;
};

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    std::cout << "not the constractor has been called" << std::endl;
    if (grade < HIGHEST_GRADE)
        throw (GradeTooHighException());
    else if (grade > LOWEST_GRADE)
        throw (GradeTooLowException());
    this->_grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    *this = copy;
    std::cout << "copy constractor has been called" << std::endl;
};

// if we init bureau here and threw excep
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &source) 
{
    if (this != &source)
    {
        (std::string)this->_name = source._name;
        this->_grade = source._grade;
    }
    return (*this);
}

const std::string& Bureaucrat::getName(void) const 
{
    return _name;
};

int Bureaucrat::getGrade(void) const 
{
    return _grade;
};

void Bureaucrat::setGrade(int grade)
{
    if (grade < HIGHEST_GRADE)
        throw (GradeTooHighException());
    else if (grade > LOWEST_GRADE)
        throw (GradeTooLowException());
    this->_grade = grade;
};

int Bureaucrat::increment(void)
{
    if (_grade == HIGHEST_GRADE)
        throw (GradeTooHighException());
    --_grade;
    return _grade;
};

int Bureaucrat::decrement(void)
{
    if (_grade == LOWEST_GRADE)
        throw (GradeTooLowException());
    ++_grade;
    return _grade;
};

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "distractor has benn called" << std::endl;
};

//#####################

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
};