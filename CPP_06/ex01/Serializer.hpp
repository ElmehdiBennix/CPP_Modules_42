#ifndef SERIALIZER_HPP__
#define SERIALIZER_HPP__

#include <iostream>
#include <cstdint>

typedef struct      Data
{
    unsigned long   raw1;
    std::string     raw2;
}                   Data;

class Serializer
{
    private:
        Serializer(void);
        Serializer(const Serializer& source);

        Serializer& operator=(Serializer& source);

        ~Serializer(void);

    public:
        static  uintptr_t      serialize(Data* ptr);
        static  Data*          deserialize(uintptr_t raw);
};

#endif
