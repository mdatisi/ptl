#ifndef ELT_1_HPP
#define ELT_1_HPP

#include "elt_base.hpp"

#include <string>

//------------------------------------------------------------------------------
class elt_1 : public elt_base
{
public:
    std::string method_of_elt_1();


private:    
    VISITABLE("ELT_1")
};

#endif
