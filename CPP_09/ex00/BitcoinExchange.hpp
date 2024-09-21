#if !defined(BITCOINEEXCHANGE_HPP__)
#define BITCOINEEXCHANGE_HPP__

#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>
#include <map>
#include <cstdlib>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

#ifndef DATA_FILE
#define DATA_FILE "./cpp_09/test.csv"
// #define DATA_FILE "./cpp_09/data.csv"
#endif // !DATAFILE

enum Errors {
    SUCCESS   = 0,
    BADINPUT  = -1,
    OVERLIMIT = -2,
    NEGATIVE  = -3,
};

#define COUT(out) std::cout << GREEN << out << RESET << std::endl
#define CWAR(out) std::cout << YELLOW << out << RESET << std::endl
#define CERR(out) std::cerr << RED << out << RESET << std::endl


typedef std::map<int, float> dataPoint;

class Bitcoin
{
    private:
        dataPoint                    dataBase;

    private:
        int     parseDate(const std::string &date) const;
        float   parseValue(const std::string &value, float min, float max) const;

        bool    parseCsv(std::ifstream &dataFile);
        void    executeExchange(std::ifstream &inputFile) const;

    public:
        Bitcoin(void);
        Bitcoin(const Bitcoin& source);

        Bitcoin& operator=(const Bitcoin &source);

        void     exchange(const char *fileName) const;

        ~Bitcoin(void);
};

template<typename T, typename Y>
std::ostream& operator<<(const std::ostream& os, const std::map<T, Y>& dataBase)
{
    for(std::map<T, Y>::const_iterator it = dataBase.begin(); it != dataBase.end() ;++it)
        os << "key: " << it->first << " | value: " << it->second << std::endl;
    return os;
}

#endif
