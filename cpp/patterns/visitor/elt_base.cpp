#include "elt_base.hpp"

#include <iostream>

using namespace std;

elt_base::key_set_t s_keys;


//------------------------------------------------------------------------------
void elt_base::accept(visitor& v)
{
    accept_(v);
};

void elt_base::accept_(visitor& v)
{
    cerr << "External actions not permitted on this object" << endl;
};


void elt_base::visitor::visit(elt_base* p)
{
    cerr << "Action is not defined" << endl;
}

