#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("DEF"), _signator(false), _signatorGrade(0), _executionGrade(0) {
    std::cout << "Default constractor called for AForm." << std::endl;
};

AForm::AForm(const std::string& name, const int signatorGrade, const int executionGrade) : _name(name), _signator(false), _signatorGrade(signatorGrade), _executionGrade(executionGrade) {
    std::cout << "Constractor called for AForm." << std::endl;
};

// test this out after
AForm::AForm(const AForm& source) : _name(source._name), _signator(source._signator), _signatorGrade(source._signatorGrade), _executionGrade(source._executionGrade) {
    std::cout << "Copy constractor called for AForm." << std::endl;
};

//#####################################################################
//test this out

// AForm& operator=(const AForm& source) {
    // AForm tmp(source); // wont work
    // return tmp;
// };

//#####################################################################

const std::string&  AForm::getName(void) const throw() {
    return _name;
};

bool    AForm::getSignator(void) const throw() {
    return _signator;
};

int     AForm::getSignatorGrade(void) const throw() {
    return _signatorGrade;
};

int     AForm::getExecutionGrade(void) const throw() {
    return _executionGrade;
};

//#####################################################################

void AForm::beSigned(Bureaucrat& obj) {
    if (obj.getGrade() <= _signatorGrade)
    {
        _signator = true;
        return;
    }
    throw (GradeTooLowException());
};

//#####################################################################

const char* AForm::GradeTooHighException::what() const throw() {
     return ("AForm Grade is too High.");
};

const char* AForm::GradeTooLowException::what() const throw() {
    return ("AForm Grade is too Low.");
};

//#####################################################################

AForm::~AForm(void) {
    std::cout << "Destractor called for AForm." << std::endl;
};

//#####################################################################

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << obj.getName() << " Form : \nGrade to be signed = " << obj.getSignatorGrade() << "\nGrade to be executed = " << obj.getExecutionGrade() << "\nSignator status : " << ((obj.getSignator()) ? "True" : "False");
    return os;
};