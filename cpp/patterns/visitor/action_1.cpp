#include "action_1.hpp"
#include "elt_1.hpp"
#include "elt_2.hpp"

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
//Implementation for elt_1
//------------------------------------------------------------------------------



action_1::action_1() : visited_base::visitor(
{
    {elt_1::key, [](visited_base* p) 
        {
            cout << "In ACTION_1::ELT_1 handler" << endl;
            elt_1* e = dynamic_cast<elt_1*>(p);
            cout << e->method_of_elt_1() << endl;
        }
    }
/*    {elt_2::key, [](visited_base* p)
        {
            cout << "In ACTION_1::ELT_2 handler" << endl;
            elt_2* e = dynamic_cast<elt_2*>(p);
            cout << e->method_of_elt_2() << endl;            
        }
    },*/
/*    {"", [](visited_base* p)
        {
            cout << "In ACTION_1::ERROR handler" << endl;
            cout << "ERROR" << endl;
        }
    }*/
})
{}



void action_1::visit(visited_base* p)
{
    cout << "key : " << p->unique_key() << endl;


    //[TODO] Manage unknown or unsupported keys
    m_key_map[get_safe_key(p)](p);
}

