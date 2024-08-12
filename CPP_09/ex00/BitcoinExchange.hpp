#if !defined(BITCOINEEXCHANGE_HPP__)
#define BITCOINEEXCHANGE_HPP__

#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>
#include <map>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

#ifndef DATA_FILE
#define DATA_FILE "./cpp_09/data.csv"
#endif // !DATAFILE

typedef enum Errors {
    SUCCESS,
    BADINPUT,
    BADFORMAT,
    OVERLIMIT,
    NEGATIVE,
} Errors;

#define COUT(out) std::cout << GREEN << out << RESET << std::endl
#define CWAR(out) std::cout << YELLOW << out << RESET << std::endl
#define CERR(out) std::cerr << RED << out << RESET << std::endl

class Bitcoin 
{
    private:
        typedef std::map<std::string, float> dataPoint;
        dataPoint       dataBase;

    private:
        bool    parseCsv(std::ifstream &dataFile);
        bool    parseDate(const std::string &date);
        float   parseValue(const std::string &date);
        // bool readFile(std::ifstream& file, dataPoint &savePoint);

    public:
        Bitcoin(void);
        Bitcoin(const Bitcoin& source);

        Bitcoin& operator=(const Bitcoin &source);

        void     exchange(const char *fileName) const;

        ~Bitcoin(void);
};

#endif
