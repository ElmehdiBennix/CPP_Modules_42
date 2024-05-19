#ifndef PRESIDENTIALPARDONFORM_HPP__
#define PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonFrom : public AForm {
    public :
        PresidentialPardonFrom(void);
        PresidentialPardonFrom(const std::string &name);
        // PresidentialPardonFrom(const PresidentialPardonFrom& source);

        void execute(const Bureaucrat& executor) const ;

        ~PresidentialPardonFrom(void);
};

#endif