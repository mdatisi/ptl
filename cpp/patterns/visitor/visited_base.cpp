#include "visited_base.hpp"

using namespace std;

visited_base::key_set_t s_keys;

//------------------------------------------------------------------------------
void visited_base::accept(visitor& v)
{
    accept_(v);
};

void visited_base::accept_(visitor& v)
{
};

void visited_base::visitor::visit(visited_base* p)
{
}

