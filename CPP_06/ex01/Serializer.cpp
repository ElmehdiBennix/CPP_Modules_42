#include "Serializer.hpp"

Serializer::Serializer(void)
{
};

Serializer::Serializer(const Serializer& source)
{
    (void)source;
};

Serializer&
Serializer::operator=(Serializer& source)
{
    (void) source;
    return (*this);
};

Serializer::~Serializer(void)
{
};


uintptr_t
Serializer::serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
};

Data*
Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
};
