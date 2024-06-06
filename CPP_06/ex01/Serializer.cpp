#include "Serializer.hpp"

Serializer::Serializer(void)
{};

Serializer::Serializer(Serializer& source)
{};

Serializer& Serializer::operator=(Serializer& source)
{};

Serializer::~Serializer(void)
{};



uintptr_t Serializer::serialize(Data* ptr)
{
    std::uintptr_t ret = reinterpret_cast<std::uintptr_t>(ptr);

    return ret;
};

Data* Serializer::Deserialize(uintptr_t ptr)
{
    return (reinterpret_cast<Data *>(ptr));
};

