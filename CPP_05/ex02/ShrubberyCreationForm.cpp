#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("DEF", 145, 137) {
    std::cout << "Default constractor called for ShrubberyCreationForm." << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name) : AForm(name, 145, 137) {
    std::cout << "Constractor called for ShrubberyCreationForm." << std::endl;
};

// ShrubberyCreationForm(const ShrubberyCreationForm& source) : AForm("DEF", 145, 137) {
//     std::cout << "copy constractor has been called." << std::endl;
// };

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (this->getSignator() && executor.getGrade() <= this->getExecutionGrade())
    {
        std::fstream out;
        out.open(executor.getName() + "_shrubbery", std::ios::out | std::ios::trunc);
        if (!out.is_open())
            std::cerr << "failed to open fd." << std::endl;
        out << ASCII_TREE << std::endl;
        out.close();
        return ;
    }
    throw(GradeTooLowException());
};

ShrubberyCreationForm::~ShrubberyCreationForm(void) {};