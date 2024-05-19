#ifndef PRESIDENTIALPARDONFORM_HPP__
#define PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"

class PresidentialPardonFrom : public AForm {
    public :
        PresidentialPardonFrom(void) : AForm("DEF", 25, 5) {
            std::cout << "Default constractor called for PresidentialPardonFrom." << std::endl;
        };

        PresidentialPardonFrom(const std::string &name) : AForm(name, 25, 5) {
            std::cout << "Constractor called for PresidentialPardonFrom." << std::endl;
        };

        // PresidentialPardonFrom(const PresidentialPardonFrom& source) : AForm("DEF", 25, 5) {
        //     std::cout << "copy constractor has been called." << std::endl;
        // };

        void execute(const Bureaucrat& executor) const {
            if (this->getSignator() && executor.getGrade() <= this->getExecutionGrade())
            {
                std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
                return ;
            }
            throw(GradeTooLowException());
        };

        ~PresidentialPardonFrom(void) {};
};

#endif