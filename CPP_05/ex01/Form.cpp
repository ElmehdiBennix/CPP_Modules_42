#include "Form.hpp"

Form::Form(void)
{
    std::cout << "default constra called " << std::endl;
};

Form::Form(const std::string& name)
{
    std::cout << "default constra called " << std::endl;
};

Form::Form(const Form& source)
{

};

Form& Form::operator=(const Form& source)
{

};

const std::string&  Form::getName(void)
{

};

bool    Form::getSignator(void)
{

};

int     Form::getSignatorGrade(void)
{

};

int     Form::getExecutionGrade(void)
{

};

void    Form::beSigned(const Bureaucrat& obj)
{

};

void    Form::signForm(const Bureaucrat& obj)
{

};

Form::~Form(void)
{

};