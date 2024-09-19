#include "Serializer.hpp"

int main(void)
{
    Data original;
    original.raw1 = 1234566789;
    original.raw2 = "hello world.";


    std::cout << "<==================" << " data size " << "==================>" << std::endl;
    std::cout << "size of uintprt_t = " << sizeof(uintptr_t) << " byts" << std::endl;
    std::cout << "size of data = " << sizeof(Data) << " byts" << std::endl;
    std::cout << "size of ul = " << sizeof(unsigned long) << " byts" << std::endl;
    std::cout << "size of string = " << sizeof(std::string) << " byts" << std::endl;


    std::cout << "<==================" << " original data " << "==================>" << std::endl;
    std::cout << "data = " << original.raw1 << std::endl;
    std::cout << "data = " << original.raw2 << std::endl;
    std::cout << "addr = " << &original.raw1 << std::endl;
    std::cout << "addr = " << &original.raw2 << std::endl;


    std::cout << "<==================" << " calling Serializer " << "==================>" << std::endl;
    uintptr_t ptr = Serializer::serialize(&original);
    std::cout << "uintptr_t data = " << ptr << std::endl;
    std::cout << "uintptr_t addr = " << &ptr << std::endl;
    std::cout << "Serialize data = " << *(reinterpret_cast<unsigned long *>(ptr)) << std::endl;
    std::cout << "Serialize data = " << *(reinterpret_cast<std::string *>(8 + ptr)) << std::endl;
    std::cout << "Serialize addr = " << (reinterpret_cast<unsigned long *>(ptr)) << std::endl;
    std::cout << "Serialize addr = " << (reinterpret_cast<std::string *>(8 + ptr)) << std::endl;


    std::cout << "<==================" << " calling deserializr " << "==================>" << std::endl;
    Data * deserialized = Serializer::deserialize(ptr);
    if (deserialized == &original) {
        std::cout << "Deserialization success, The deserialized pointer is equal to the original pointer." << std::endl;
    } else {
        std::cout << "Deserialization failed. The pointers do not match the original." << std::endl;
    }
    std::cout << "deserialize data = " << deserialized->raw1 << std::endl;
    std::cout << "deserialize data = " << deserialized->raw2 << std::endl;
    std::cout << "deserialize addr = " << &deserialized->raw1 << std::endl;
    std::cout << "deserialize addr = " << &deserialized->raw2 << std::endl;

    return 0;
}
