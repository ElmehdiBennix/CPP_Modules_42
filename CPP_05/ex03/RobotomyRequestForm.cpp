#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("DEF", 72, 45) {
    std::cout << "Default constractor called for RobotomyRequestForm." << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const std::string &name) : AForm(name, 72, 45) {
    std::cout << "Constractor called for RobotomyRequestForm." << std::endl;
};

// RobotomyRequestForm(const RobotomyRequestForm& source) : AForm("DEF", 72, 45) {
//     std::cout << "copy constractor has been called." << std::endl;
// };

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (this->getSignator() && executor.getGrade() <= this->getExecutionGrade())
    {
        for (int i = 0; i <= LOAD; i++)
        {
            std::string noise("Drilling noises.");
            noise += ".";
            std::cout << noise  << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        (std::rand() % 2) ? std::cout << executor.getName() << " has been robotomized successfully." : std::cout << "Robotomy failed...";
        std::cout << std::endl;
        return;
    }
    throw(GradeTooLowException());
};

RobotomyRequestForm::~RobotomyRequestForm(void) {};