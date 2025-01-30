#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T &element)
{
    std::cout << element << " ";
}

void increment(int &element)
{
    element += 1;
}

void toUpper(char &element)
{
    if (element >= 'a' && element <= 'z')
    {
        element = element - 'a' + 'A';
    }
}

int main()
{

    int intArray[] = {1, 2, 3, 4, 5};                                  // 5 int
    std::size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]); // 5 * 4 bytes = 20 ==> 20/4= 5 elements

    std::cout << "Original int array: ";
    iter(intArray, intArraySize, printElement);
    std::cout << "\n";

    iter(intArray, intArraySize, increment);

    std::cout << "Modified int array (after increment): ";
    iter(intArray, intArraySize, printElement);
    std::cout << "\n";

    char charArray[] = {'h', 'e', 'l', 'l', 'o'};
    std::size_t charArraySize = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "Original char array: ";
    iter(charArray, charArraySize, printElement);
    std::cout << "\n";

    iter(charArray, charArraySize, toUpper);

    std::cout << "Modified char array (after toUpper): ";
    iter(charArray, charArraySize, printElement);
    std::cout << "\n";

    std::string strArray[] = {"apple", "banana", "cherry"};
    std::size_t strArraySize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array: ";
    iter(strArray, strArraySize, printElement);
    std::cout << "\n";

    return 0;
}
