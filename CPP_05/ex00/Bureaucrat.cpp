#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
};

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    if (grade < HIGHEST_GRADE)
        throw (GradeTooHighException());
    else if (grade > LOWEST_GRADE)
        throw (GradeTooLowException());
    this->_grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat &source)
{
    *this = source;
};

Bureaucrat&
Bureaucrat::operator=(const Bureaucrat &source)
{
    if (this != &source)
        this->_grade = source._grade;
    return (*this);
}

const std::string&
Bureaucrat::getName(void) const
{
    return _name;
};

int
Bureaucrat::getGrade(void) const
{
    return _grade;
};

int
Bureaucrat::increment(void)
{
    if (_grade == HIGHEST_GRADE)
        throw (GradeTooHighException());
    --_grade;
    return _grade;
};

int
Bureaucrat::decrement(void)
{
    if (_grade == LOWEST_GRADE)
        throw (GradeTooLowException());
    ++_grade;
    return _grade;
};

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "destructor has been called for " << _name << std::endl;
};


const char*
Bureaucrat::GradeTooHighException::what() const throw() {
    return ("The Grade is too high");
};

const char*
Bureaucrat::GradeTooLowException::what() const throw() {
    return ("The Grade is too low");
};


std::ostream&   operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
};
