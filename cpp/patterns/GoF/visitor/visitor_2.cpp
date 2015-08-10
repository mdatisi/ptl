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

//MODULE
#include "visitor_2.hpp"
#include "elt_1.hpp"
#include "elt_2.hpp"

//C++ STANDARD
#include<iostream>

using namespace std;

//------------------------------------------------------------------------------
visitor_2::visitor_2() : visited_base::visitor(
{
    //--------------------------------------------------------------------------
    {elt_1::key, [](visited_base* vted) 
        {
            elt_1* e = dynamic_cast<elt_1*>(vted);
            cout << "visitor_2 : elt_1 : " << e->method_of_elt_1() << endl;
        }
    },

    //--------------------------------------------------------------------------
    {elt_2::key, [](visited_base* vted)
        {
            elt_2* e = dynamic_cast<elt_2*>(vted);
            cout << "visitor_2 : elt_2 : " << e->method_of_elt_2() << endl;
        }
    }

    //--------------------------------------------------------------------------
    //Note : This visitor does NOT handle the 'empty' key case
})
{
}
