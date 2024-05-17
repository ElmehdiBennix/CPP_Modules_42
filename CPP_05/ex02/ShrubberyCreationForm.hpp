#ifndef SHRUBBERYCREATIONFORM_HPP__
#define SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private :

    public :
        ShrubberyCreationForm(void) : AForm("DEF", 145, 137) {
            std::cout << "default constractor has been called." << std::endl;
        };

        ShrubberyCreationForm(const std::string &name) : AForm(name, 145, 137) {
            std::cout << "constractor has been called." << std::endl;
        };

        ShrubberyCreationForm(const ShrubberyCreationForm& source) : AForm("DEF", 145, 137) {
            std::cout << "copy constractor has been called." << std::endl;
        };



        ~ShrubberyCreationForm(void) throw();
};

#endif