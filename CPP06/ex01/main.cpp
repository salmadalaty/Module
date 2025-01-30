#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{

    Data original;
    original.name = "Serialization Example";

    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized uintptr_t: " << serialized << std::endl;

    Data *deserialized = Serializer::deserialize(serialized);

    if (deserialized == &original)
    {
        std::cout << "Deserialization successful!" << std::endl;
    }
    else
    {
        std::cout << "Deserialization failed!" << std::endl;
    }

    return 0;
}
