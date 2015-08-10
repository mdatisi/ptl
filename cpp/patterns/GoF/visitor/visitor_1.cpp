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

#include "visitor_1.hpp"
#include "elt_1.hpp"
#include "elt_2.hpp"

#include <iostream>

using namespace std;

visitor_1::visitor_1() : visited_base::visitor(
{
//------------------------------------------------------------------------------
    {elt_1::key, [](visited_base* vted) 
        {
            elt_1* e = dynamic_cast<elt_1*>(vted);
            cout << "visitor_1 : elt_1 : " << e->method_of_elt_1() << endl;
        }
    },

//------------------------------------------------------------------------------
    {elt_2::key, [](visited_base* vted)
        {
            elt_2* e = dynamic_cast<elt_2*>(vted);
            cout << "visitor_1 : elt_2 : " << e->method_of_elt_2() << endl;
        }
    },
    
//------------------------------------------------------------------------------
    {"", [](visited_base* vted)
        {
            cerr << "visitor_1 : " << vted->unique_key() << " is non handled" << endl;
        }
    }
})
{
}
