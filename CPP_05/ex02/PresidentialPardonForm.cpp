#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

#define GRADE 25
#define EXEC 5

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("DEF", GRADE, EXEC)
{
};

PresidentialPardonForm::PresidentialPardonForm(const std::string &name) : AForm(name, GRADE, EXEC)
{
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source) : AForm(source.getName(), GRADE, EXEC)
{
};

PresidentialPardonForm&
PresidentialPardonForm::operator=(const PresidentialPardonForm& source)
{
    if (this != &source)
        *this = source;
    return (*this);
};

void
PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (this->getSignator() && executor.getGrade() <= this->getExecutionGrade())
    {
        std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
        return ;
    }
    throw(GradeTooLowException());
};

PresidentialPardonForm::~PresidentialPardonForm(void)
{
};
