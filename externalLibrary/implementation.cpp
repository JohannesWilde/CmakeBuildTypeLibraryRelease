#include <externalLibrary/publicHeader.hpp>
#include "privateHeader.hpp"

#include <iostream>


void somePrivateMethod()
{
    std::cout << "somePrivateMethod called." << std::endl;
}

void someMethod()
{
    somePrivateMethod();
    std::cout << "someMethod called: ";
#ifdef NDEBUG
    std::cout << "Release";
#else
    std::cout << "Debug";
#endif
    std::cout << std::endl;
}
