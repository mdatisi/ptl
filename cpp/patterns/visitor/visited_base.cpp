#include "visited_base.hpp"

#include <iostream>

using namespace std;

visited_base::key_set_t visited_base::s_keys;

//------------------------------------------------------------------------------
void visited_base::accept(visitor& v)
{
    accept_(v);
};

void visited_base::accept_(visitor& v)
{
};

//------------------------------------------------------------------------------
visited_base::visitor::visitor(const key_map_t& key_map ) :
    m_key_map(key_map)
{
    //Adds "empty key" if the derived class didn't add it itself
    if (m_key_map.find("") == m_key_map.end())
    {
        m_key_map[""] = [](visited_base* p) {
            cerr << "element " << p->unique_key() << " is not supported by this visitor" << endl;
        };
    }
}

void visited_base::visitor::visit(visited_base* p)
{
}

string visited_base::visitor::get_safe_key(visited_base* p) const
{
    //Check if the visited_base key is in the key map of the visitor
    //returns empty string if not
    string key = p->unique_key();
    auto it = m_key_map.find(key); 
    if (it != m_key_map.end())
        return key;
    return "";
}
