#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("DEF"), _signator(false), _signatorGrade(150), _executionGrade(150)
{
};

AForm::AForm(const std::string& name, const int signatorGrade, const int executionGrade) : _name(name), _signator(false), _signatorGrade(signatorGrade), _executionGrade(executionGrade)
{
    if (signatorGrade < HIGHEST_GRADE || executionGrade < HIGHEST_GRADE )
        throw (GradeTooHighException());
    else if (signatorGrade > LOWEST_GRADE || executionGrade > LOWEST_GRADE)
        throw (GradeTooLowException());
};

AForm::AForm(const AForm& source) : _name(source._name), _signator(source._signator), _signatorGrade(source._signatorGrade), _executionGrade(source._executionGrade)
{
};

AForm&
AForm::operator=(const AForm& source)
{
    if (this != &source)
        _signator = source._signator;
    return (*this);
};

const std::string&
AForm::getName(void) const throw()
{
    return _name;
};

bool
AForm::getSignator(void) const throw()
{
    return _signator;
};

int
AForm::getSignatorGrade(void) const throw()
{
    return _signatorGrade;
};

int
AForm::getExecutionGrade(void) const throw()
{
    return _executionGrade;
};

void
AForm::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() <= _signatorGrade)
    {
        _signator = true;
        return;
    }
    throw (GradeTooLowException());
};

AForm::~AForm(void)
{
    std::cout << "destructor has been called for Aform " << _name << std::endl;
};


const char*
AForm::GradeTooHighException::what() const throw()
{
    return ("AForm Grade is too High");
}

const char*
AForm::GradeTooLowException::what() const throw()
{
    return ("AForm Grade is too Low");
};


std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << obj.getName() << " AForm : " << std::endl \
        << "Grade to be signed = " << obj.getSignatorGrade() << std::endl \
        << "Grade to be executed = " << obj.getExecutionGrade() << std::endl \
        << "Signator status : " << ((obj.getSignator()) ? "True" : "False");
    return os;
};
