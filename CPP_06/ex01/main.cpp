#include "Serializer.hpp"

int main(void)
{
    Data *test = new Data;

    test->raw1 = 1234566789;
    test->raw2 = "yes this is real.";

    std::cout << "data = " << test->raw1 << std::endl;
    std::cout << "data = " << test->raw2 << std::endl;
    std::cout << "addr = " << &test->raw1 << std::endl;
    std::cout << "addr = " << &test->raw2 << std::endl;
// uintptr is just an unsiged int that can hold a pointer it just represent a pointer as an int this is usefull in platfroms where pointer size may vary 
    std::cout << "size of uintprt_t = " << sizeof(std::uintptr_t) << " byts" << std::endl;
    std::cout << "size of data = " << sizeof(Data) << " byts" << std::endl;
    std::cout << "size of ul = " << sizeof(unsigned long) << " byts" << std::endl;
    std::cout << "size of string = " << sizeof(std::string) << " byts" << std::endl;

    std::cout << "calling Serializer " << std::endl;
    std::uintptr_t ptr = Serializer::serialize(test);
    std::cout << "after Serialize data = " << *(reinterpret_cast<unsigned long *>(ptr)) << std::endl;
    std::cout << "after Serialize data = " << *(reinterpret_cast<std::string *>(8 + ptr)) << std::endl;
    std::cout << "after Serialize addr = " << (reinterpret_cast<unsigned long *>(ptr)) << std::endl;
    std::cout << "after Serialize addr = " << (reinterpret_cast<std::string *>(8 + ptr)) << std::endl;

    std::cout << "calling deserializr " << std::endl;
    test = NULL;
    test = Serializer::Deserialize(ptr);
    std::cout << "after deSerialize data = " << test->raw1 << std::endl;
    std::cout << "after deSerialize data = " << test->raw2 << std::endl;
    std::cout << "after deSerialize addr = " << test->raw1 << std::endl;
    std::cout << "after deSerialize addr = " << test->raw2 << std::endl;

    delete test;
}