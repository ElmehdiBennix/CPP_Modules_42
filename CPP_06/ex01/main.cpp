#include "Serializer.hpp"

// int main(void)
// {
//     // Data x = {123456789};
//     Data *test = new Data;

//     test->raw = 1234566789;

//     std::cout << "before Serializer = " << test->raw << std::endl;
//     std::uintptr_t ptr = Serializer::serialize(test);
//     std::cout << "after Serialize = " << ptr << std::endl;

//     std::cout << "before deSerialize = " << ptr << std::endl;
//     test = Serializer::deserialize(ptr);
//     std::cout << "after deSerialize = " << test->raw << std::endl;

//     delete test;
// }

// #include "climits"

// int main(void)
// {
//     long x = LONG_MAX;

//     int w = static_cast<int>(x);
// }