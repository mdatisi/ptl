#ifndef ELT_2_HPP
#define ELT_2_HPP

#include "elt_base.hpp"

#include <string>

//------------------------------------------------------------------------------
class elt_2 : public elt_base
{
public:
    std::string method_of_elt_2();

private:    
    VISITABLE("ELT_2")
};

#endif
