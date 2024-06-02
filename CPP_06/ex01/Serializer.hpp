#ifndef SERIALIZER_HPP__
#define SERIALIZER_HPP__

#include <iostream>
#include <cstdint>

typedef data {
    int example;
} Data;

class Serializer
{
    private:
        Serializer(void);
        Serializer(Serializer& obj);
        ~Serializer(void);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* Deserialize(uintptr_t ptr);
}

#endif