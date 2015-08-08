#include "action_1.hpp"
#include "elt_1.hpp"
#include "elt_2.hpp"

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
//Implementation for elt_1
//------------------------------------------------------------------------------



action_1::action_1() : elt_base::visitor(
{
    {elt_1::key, [](elt_base* p) 
        {
            cout << "In ACTION_1::ELT_1 handler" << endl;
            elt_1* e = dynamic_cast<elt_1*>(p);
            cout << e->method_of_elt_1() << endl;
        }
    },
    {elt_2::key, [](elt_base* p)
        {
            cout << "In ACTION_1::ELT_2 handler" << endl;
            elt_2* e = dynamic_cast<elt_2*>(p);
            cout << e->method_of_elt_2() << endl;            
        }
    },
    {"", [](elt_base* p)
        {
            cout << "In ACTION_1::ERROR handler" << endl;
            cout << "ERROR" << endl;
        }
    }
})
{}



void action_1::visit(elt_base* p)
{
    cout << "key : " << p->unique_key() << endl;
    m_key_map[p->unique_key()](p);
}

