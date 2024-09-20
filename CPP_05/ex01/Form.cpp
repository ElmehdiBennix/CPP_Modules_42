#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("DEF"), _signator(false), _signatorGrade(150), _executionGrade(150)
{
};

Form::Form(const std::string& name, const int signatorGrade, const int executionGrade) : _name(name), _signator(false), _signatorGrade(signatorGrade), _executionGrade(executionGrade)
{
    if (signatorGrade < HIGHEST_GRADE || executionGrade < HIGHEST_GRADE )
        throw (GradeTooHighException());
    else if (signatorGrade > LOWEST_GRADE || executionGrade > LOWEST_GRADE)
        throw (GradeTooLowException());
};

Form::Form(const Form& source) : _name(source._name), _signator(source._signator), _signatorGrade(source._signatorGrade), _executionGrade(source._executionGrade)
{
};

Form&   Form::operator=(const Form& source)
{
    Form tmp(source);
    return tmp;
};

const std::string&
Form::getName(void) const throw()
{
    return _name;
};

bool
Form::getSignator(void) const throw()
{
    return _signator;
};

int
Form::getSignatorGrade(void) const throw()
{
    return _signatorGrade;
};

int
Form::getExecutionGrade(void) const throw()
{
    return _executionGrade;
};

void
Form::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() <= _signatorGrade)
    {
        _signator = true;
        return;
    }
    throw (GradeTooLowException());
};

Form::~Form(void)
{
    std::cout << "Destractor called for form " << _name << std::endl;
};


const char*
Form::GradeTooHighException::what() const throw()
{
    return ("Form Grade is too High");
}

const char*
Form::GradeTooLowException::what() const throw()
{
    return ("Form Grade is too Low");
};


std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << obj.getName() << " Form : " << std::endl << "Grade to be signed = " << obj.getSignatorGrade() << "\nGrade to be executed = " << obj.getExecutionGrade() << std::endl << "Signator status : " << ((obj.getSignator()) ? "True" : "False");
    return os;
};
