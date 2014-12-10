//Module
#include "../include/class.hpp"
#include "version.hpp"

//C++ Standard Library
#include <iostream>

auto main(int argc, char* argv[]) -> int
{
try
{
    using namespace std;
    cout << "Welcome to " << magic::project_name_version << endl;

    MyClass::my_function();
    return 0;
}
catch(...)
{
    std::cerr << "Unspecified exception caught at main level" << std::endl;
}
}
