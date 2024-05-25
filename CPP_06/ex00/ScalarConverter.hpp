#ifndef SCALARCONVERTER_HPP__
#define SCALARCONVERTER_HPP__

#include <iostream>
#include <limits>
#include <iomanip> 

class ScalarConverter {
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& source);
        void operator=(const ScalarConverter& source);

        static bool isChar(const std::string &type) throw();
        static bool isInt(const std::string &type) throw();
        static bool isFloat(const std::string &type) throw();
        static bool isDouble(const std::string &type) throw();

        // static void convertFromChar(char c) throw();
        static void convertFromInt(const std::string &type) throw();
        static void convertFromFloat(const std::string &type) throw();
        static void convertFromDouble(const std::string &type) throw();

        ~ScalarConverter(void);

    public:
        static void convert(const std::string& literal) throw();
};

#endif