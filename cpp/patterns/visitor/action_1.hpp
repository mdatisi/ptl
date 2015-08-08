#ifndef ACTION_1_HPP
#define ACTION_1_HPP

#include "elt_base.hpp"




//------------------------------------------------------------------------------
class action_1: public elt_base::visitor
{
public:
        action_1();

private:
        void visit(elt_base* p) override;
};

#endif 
