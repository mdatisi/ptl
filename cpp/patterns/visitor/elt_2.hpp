#ifndef ELT_2_HPP
#define ELT_12HPP

#include "elt_base.hpp"

#include <string>

//------------------------------------------------------------------------------
class elt_2 : public elt_base
{
public:
    static const std::string key;



    std::string method_of_elt_2();


private:    
    VISITABLE(key);
};

#endif
