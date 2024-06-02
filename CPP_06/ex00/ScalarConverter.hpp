#ifndef SCALARCONVERTER_HPP__
#define SCALARCONVERTER_HPP__

#include <iostream>
#include <sstream>
#include <cmath>

class ScalarConverter {
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& source);
        void operator=(const ScalarConverter& source);
        ~ScalarConverter(void);

    public:
        static void convert(const std::string& literal) throw();
};

#endif