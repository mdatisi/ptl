#ifndef ACTION_1_HPP
#define ACTION_1_HPP

#include "visited_base.hpp"

//------------------------------------------------------------------------------
class action_1: public visited_base::visitor
{
public:
        action_1();

private:
        void visit(visited_base* p) override;
};

#endif 
