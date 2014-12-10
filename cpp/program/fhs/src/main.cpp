//Module
#include "../include/class.hpp"

//C++ Standard Library
#include <iostream>

int main()
{
try{
    MyClass::my_function();
    throw 0;
    return 0;
}
catch(...) {
    std::cerr << "Unspecified exception caught at main level" << std::endl;
}
}
