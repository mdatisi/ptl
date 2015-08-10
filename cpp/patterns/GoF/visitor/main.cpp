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
#include "elt_1.hpp"
#include "elt_2.hpp"
#include "elt_3.hpp"
#include "visitor_1.hpp"
#include "visitor_2.hpp"

//------------------------------------------------------------------------------
int main()
{
    elt_1 e1;
    elt_2 e2;
    elt_3 e3;

    visitor_1 v1 ;
    e1.accept(v1);
    e2.accept(v1);
    e3.accept(v1);


    visitor_2 v2 ;
    e1.accept(v2);
    e2.accept(v2);
    e3.accept(v2);
}
