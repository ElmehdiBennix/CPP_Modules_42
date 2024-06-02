#ifndef SERIALIZER_HPP__
#define SERIALIZER_HPP__

#include <iostream>
#include <cstdint>

typedef struct data {
    unsigned long raw;
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