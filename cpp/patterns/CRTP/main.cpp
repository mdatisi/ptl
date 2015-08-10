//------------------------------------------------------------------------------
// [CRTP PATTERN IMPLEMENTATION]
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

#include <iostream>

//------------------------------------------------------------------------------
template <typename DERIVED>
class base_class
{
public:
        void statically_virtual_function()
        {
            impl()->statically_virtual_function_implementation();
        }

private:
    DERIVED* impl()
    {
        return static_cast<DERIVED*>(this);
    }
};

//------------------------------------------------------------------------------
class derived_class : public base_class<derived_class>
{
private:
    void statically_virtual_function_implementation()
    {
        std::cout << "statically_virtual_function_implementation" 
             << std::endl;
    }

    friend class base_class<derived_class>;
};

//------------------------------------------------------------------------------
int main()
{
    derived_class d;
    d.statically_virtual_function();
}
