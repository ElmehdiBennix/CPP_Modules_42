#include "Bureaucrat.hpp"

//#####################

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("The Grade is too high");
};

//#####################

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("The Grade is too low");
};

//#####################

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

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    *this = copy;
};

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
};

//#####################

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
};
