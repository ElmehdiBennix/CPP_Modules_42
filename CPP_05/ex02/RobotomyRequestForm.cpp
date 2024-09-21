#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#define GRADE 72
#define EXEC 45
#define LOAD 5

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("DEF", GRADE, EXEC)
{
};

RobotomyRequestForm::RobotomyRequestForm(const std::string &name) : AForm(name, GRADE, EXEC)
{
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source) : AForm(source.getName(), GRADE, EXEC)
{
};

RobotomyRequestForm&
RobotomyRequestForm::operator=(const RobotomyRequestForm& source)
{
    if (this != &source)
        *this = source;
    return (*this);
};

void
RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (this->getSignator() && executor.getGrade() <= this->getExecutionGrade())
    {
        for (int i = 0; i <= LOAD; i++)
        {
            std::string noise("Drilling noises.");
            noise += ".";
            std::cout << noise << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        std::cout << executor.getName() << ((std::rand() % 2) ? " has been robotomized successfully." : " robotomy failed...") << std::endl;
        return;
    }
    throw(GradeTooLowException());
};

RobotomyRequestForm::~RobotomyRequestForm(void)
{
};
