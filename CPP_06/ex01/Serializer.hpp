#ifndef SERIALIZER_HPP__
#define SERIALIZER_HPP__

#include <iostream>
#include <cstdint>

typedef struct data {
    unsigned long raw1;
    std::string   raw2;
} Data;

class Serializer
{
    private:
        Serializer(void);
        Serializer(Serializer& source);
        Serializer& operator=(Serializer& source);
        ~Serializer(void);

    public:
        static std::uintptr_t serialize(Data* ptr);
        static Data*          Deserialize(std::uintptr_t ptr);
};

#endif