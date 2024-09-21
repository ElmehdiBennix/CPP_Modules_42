#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

#define GRADE 145
#define EXEC 137

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("DEF", GRADE, EXEC)
{
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name) : AForm(name, GRADE, EXEC)
{
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& source) : AForm(source.getName(), GRADE, EXEC)
{
};

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(const ShrubberyCreationForm& source)
{
    if (this != &source)
        *this = source;
    return (*this);
};

void
ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (this->getSignator() && executor.getGrade() <= this->getExecutionGrade())
    {
        std::fstream out;
        out.open(executor.getName() + "_shrubbery", std::ios::out | std::ios::trunc);
        if (!out.is_open())
            std::cerr << "Error: failed to open fd." << std::endl;
        out << ASCII_TREE << std::endl;
        out.close();
        return ;
    }
    throw(GradeTooLowException());
};

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
};
