#ifndef PRESIDENTIALPARDONFORM_HPP__
#define PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public :
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string &name);
        PresidentialPardonForm(const PresidentialPardonForm& source);

        PresidentialPardonForm& operator=(const PresidentialPardonForm& source);

        void                    execute(const Bureaucrat& executor) const ;

        ~PresidentialPardonForm(void);
};

#endif
