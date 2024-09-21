#ifndef ROBOTOMYREQUESTFORM_HPP__
#define ROBOTOMYREQUESTFORM_HPP__

#include <thread>
#include <chrono>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public :
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string &name);
        RobotomyRequestForm(const RobotomyRequestForm& source);

        RobotomyRequestForm&    operator=(const RobotomyRequestForm& source);

        void                    execute(const Bureaucrat& executor) const;

        ~RobotomyRequestForm(void);
};

#endif
