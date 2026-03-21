#include <iostream>
#include <string>
#include <exception>
#include "Array.hpp"

int main() {
    std::cout << "--- 1. Default constructor (Empty Array) ---" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    std::cout << "\n--- 2. Parameterized constructor & Default init ---" << std::endl;
    Array<int> intArray(5);
    std::cout << "intArray size: " << intArray.size() << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << " (should be 0)" << std::endl;
    }

    std::cout << "\n--- 3. Modifying elements ---" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    std::cout << "\n--- 4. Copy constructor (Deep Copy Test) ---" << std::endl;
    Array<int> copyArray(intArray);
    std::cout << "Changing copyArray[0] to 999..." << std::endl;
    copyArray[0] = 999;
    std::cout << "Original intArray[0]  : " << intArray[0] << std::endl;
    std::cout << "Modified copyArray[0] : " << copyArray[0] << std::endl;

    std::cout << "\n--- 5. Assignment operator (Deep Copy Test) ---" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "Changing assignedArray[1] to 888..." << std::endl;
    assignedArray[1] = 888;
    std::cout << "Original intArray[1]     : " << intArray[1] << std::endl;
    std::cout << "Modified assignedArray[1]: " << assignedArray[1] << std::endl;

    std::cout << "\n--- 6. Out of bounds exceptions ---" << std::endl;
    try {
        std::cout << "Trying to access index -1..." << std::endl;
        intArray[-1] = 0;
        std::cout << "ERROR: This should not print!" << std::endl;
    } catch(const std::exception& e) {
        std::cout << "Exception caught successfully: " << e.what() << std::endl;
    }

    try {
        std::cout << "Trying to access index equal to size (5)..." << std::endl;
        intArray[5] = 0;
        std::cout << "ERROR: This should not print!" << std::endl;
    } catch(const std::exception& e) {
        std::cout << "Exception caught successfully: " << e.what() << std::endl;
    }

    std::cout << "\n--- 7. Complex types (std::string) ---" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "42";
    stringArray[2] = "Templates!";
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
    }

    return 0;
}