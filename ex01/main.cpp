#include <iostream>
#include <string>
#include "iter.hpp"

void incrementInt(int& n) {
    n++;
}

template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

int main() {
    std::cout << "--- TEST 1: Non-const int array ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Before: ";
    ::iter(intArray, intLen, printElement<int>); 
    std::cout << std::endl;

    ::iter(intArray, intLen, incrementInt);

    std::cout << "After:  ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::cout << "\n--- TEST 2: Const string array ---" << std::endl;
    const std::string stringArray[] = {"Hello", "42", "World", "Templates", "are", "cool!"};
    size_t stringLen = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "Elements: ";
    ::iter(stringArray, stringLen, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}