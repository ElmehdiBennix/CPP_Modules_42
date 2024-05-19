#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonFrom::PresidentialPardonFrom(void) : AForm("DEF", 25, 5) {
    std::cout << "Default constractor called for PresidentialPardonFrom." << std::endl;
};

PresidentialPardonFrom::PresidentialPardonFrom(const std::string &name) : AForm(name, 25, 5) {
    std::cout << "Constractor called for PresidentialPardonFrom." << std::endl;
};

// PresidentialPardonForm::PresidentialPardonFrom(const PresidentialPardonFrom& source) : AForm("DEF", 25, 5) {
//     std::cout << "copy constractor has been called." << std::endl;
// };

void PresidentialPardonFrom::execute(const Bureaucrat& executor) const {
    if (this->getSignator() && executor.getGrade() <= this->getExecutionGrade())
    {
        std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
        return ;
    }
    throw(GradeTooLowException());
};

PresidentialPardonFrom::~PresidentialPardonFrom(void) {};