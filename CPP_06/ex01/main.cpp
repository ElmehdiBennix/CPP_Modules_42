#include "Serialize.hpp"

int main(void)
{
    // Data x = {123456789};
    Data *test = new Data;

    test->testing = 1234566789;

    std::cout << "before Serializer = " << test->raw << std::endl;
    std::uintptr_t ptr = Serializer::serialize(test);
    std::cout << "after Serialize = " << ptr << std::endl;

    std::cout << "before deSerialize = " << ptr << std::endl;
    test = Serializer::deserialize(ptr);
    std::cout << "after deSerialize = " << test->raw << std::endl;

    delete test;
}