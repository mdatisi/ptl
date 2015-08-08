#ifndef ELT_1_HPP
#define ELT_1_HPP

#include "visited_base.hpp"

#include <string>

//------------------------------------------------------------------------------
class elt_1 : public visited_base
{
public:
    static const std::string key;

    std::string method_of_elt_1();

private:    
    VISITABLE(key);
};

#endif
