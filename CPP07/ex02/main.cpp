#include <iostream>
#include "array.hpp"

int main()
{
    try
    {

        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << "\n";

        Array<int> intArray(5);
        std::cout << "Int array size: " << intArray.size() << "\n";

        for (unsigned int i = 0; i < intArray.size(); i++)
        {
            intArray[i] = i * 10;
        }
        std::cout << "Int array elements: ";
        for (unsigned int i = 0; i < intArray.size(); i++)
        {
            std::cout << intArray[i] << " ";
        }
        std::cout << "\n";

        Array<int> copyArray = intArray;
        std::cout << "Copied array elements: ";
        for (unsigned int i = 0; i < copyArray.size(); i++)
        {
            std::cout << copyArray[i] << " ";
        }
        std::cout << "\n";

        intArray[0] = 100;
        std::cout << "Modified intArray[0]: " << intArray[0] << "\n";
        std::cout << "Copy array remains unchanged: " << copyArray[0] << "\n";

        std::cout << "Accessing out-of-bounds index...\n";
        std::cout << intArray[10] << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
