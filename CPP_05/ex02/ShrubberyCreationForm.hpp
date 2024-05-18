#ifndef SHRUBBERYCREATIONFORM_HPP__
#define SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {

    public :
        ShrubberyCreationForm(void) : AForm("DEF", 145, 137) {
            std::cout << "Default constractor called for ShrubberyCreationForm." << std::endl;
        };

        ShrubberyCreationForm(const std::string &name) : AForm(name, 145, 137) {
            std::cout << "Constractor called for ShrubberyCreationForm." << std::endl;
        };

        // ShrubberyCreationForm(const ShrubberyCreationForm& source) : AForm("DEF", 145, 137) {
        //     std::cout << "copy constractor has been called." << std::endl;
        // };

        void exec(const Bureaucrat& target) {

            (void) target;
            std::fstream out;

            out.open("l_txt", std::ios::out | std::ios::app);
            // out.open("l_txt", std::ios::out | std::ios::app | std::ios::trunc);
            if (!out.is_open())
            {
                std::cerr << "cant open bruh" << std::endl;
            }

            out << "l_txt1" << std::endl;
            out << "l_txt2" << std::endl;
            out << "l_txt3" << std::endl;

            out.close();
        };

        ~ShrubberyCreationForm(void) {};
};

#endif