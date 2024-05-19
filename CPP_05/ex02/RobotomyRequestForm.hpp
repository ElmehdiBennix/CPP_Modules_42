#ifndef ROBOTOMYREQUESTFORM_HPP__
#define ROBOTOMYREQUESTFORM_HPP__

#include "AForm.hpp"
#include <thread>  // for std::this_thread::sleep_for
#include <chrono>  // for std::chrono::milliseconds

#define LOAD 5

class RobotomyRequestForm : public AForm {
    public :
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string &name);
        // RobotomyRequestForm(const RobotomyRequestForm& source) ;

        void execute(const Bureaucrat& executor) const;

        ~RobotomyRequestForm(void);
};

#endif