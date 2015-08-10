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
#ifndef ELT_3_HPP
#define ELT_3_HPP

#include "visited_base.hpp"

#include <string>

//------------------------------------------------------------------------------
class elt_3 : public visited_base
{
public:
    static const std::string key;

    std::string method_of_elt_3();

private:    
    VISITABLE(key);
};

#endif //#ifndef ELT_3_HPP
