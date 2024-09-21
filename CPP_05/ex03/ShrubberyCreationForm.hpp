#ifndef SHRUBBERYCREATIONFORM_HPP__
#define SHRUBBERYCREATIONFORM_HPP__

#include <fstream>
#include "AForm.hpp"

#define ASCII_TREE "\
                                              .         ;  \n\
                 .              .              ;%     ;;   \n\
                   ,           ,                :;%  %;   \n\
                    :         ;                   :;%;'     .,\n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'\n\
                        `@%.  `;@%.      ;@@%;\n\
                          `@%%. `@%%    ;@@%;\n\
                            ;@%. :@%%  %@@%;\n\
                              %@bd%%%bd%%:;\n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . '\n\
                                %@@@o%;:(.,'\n\
                            `.. %@@@o%::;\n\
                               `)@@@o%::;\n\
                                %@@(o)::;\n\
                               .%@@@@%::;\n\
                               ;%@@@@%::;."

class ShrubberyCreationForm : public AForm
{
    public :
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string &name);
        ShrubberyCreationForm(const ShrubberyCreationForm& source);

        ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& source);

        void                    execute(const Bureaucrat& executor) const;

        ~ShrubberyCreationForm(void);
};

#endif
