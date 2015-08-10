//------------------------------------------------------------------------------
// [EXPERIMENTAL VISITOR PATTERN VARIANT IMPLEMENTATION]
// Copyright (C) 2015 Laurent Watteau <contact@laurent-watteau.com>
// 557 Rue des Hemmes
// 62215 OYE-PLAGE (FRANCE)
//
// This program is free software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

#include "visited_base.hpp"

#include <iostream>

visited_base::key_set_t visited_base::s_keys;

//------------------------------------------------------------------------------
void visited_base::accept(visitor& vtor)
{
    accept_(vtor);
}

void visited_base::accept_(visitor& vtor)
{
}

std::string visited_base::unique_key() const
{
    return unique_key_();
}

//------------------------------------------------------------------------------
visited_base::visitor::visitor(const key_map_t& key_map ) :
    m_key_map(key_map)
{
    //Adds "empty key" if the derived class didn't add it itself
    if (m_key_map.find("") == m_key_map.end())
    {
        m_key_map[""] = [](visited_base* vted) {
            std::cerr << "element " 
                      << vted->unique_key() 
                      << " is not supported by this visitor" 
                      << std::endl;
        };
    }
}

void visited_base::visitor::visit(visited_base* vted)
{
    m_key_map[get_safe_key(vted)](vted);
}

void visited_base::visitor::operator()(visited_base* vted)
{
    visit(vted);
}


std::string visited_base::visitor::get_safe_key(visited_base* vted) const
{
    //Check if the visited_base key is in the key map of the visitor
    //returns empty string if not
    auto key = vted->unique_key();
    auto it = m_key_map.find(key); 
    if (it != m_key_map.end())
        return key;
    return "";
}





