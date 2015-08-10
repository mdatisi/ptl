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
#ifndef VISITED_BASE_HPP
#define VISITED_BASE_HPP

#include <functional>
#include <map>
#include <string>
#include <unordered_set>

//------------------------------------------------------------------------------
class visited_base
{
public:
    using key_set_t =  std::unordered_set<std::string>;
    class visitor
    {
    public:
        using key_map_t = 
            std::map<std::string, std::function<void(visited_base*)>>; 

        visitor(const key_map_t& key_map);

        void visit(visited_base* p);

    private:
        //Returns empty string if the visitor doesn't support
        //the visited node type
        std::string get_safe_key(visited_base* p) const;

    private:
        key_map_t m_key_map;
    };

    void accept(visitor& v);

    virtual std::string unique_key() const = 0;

protected:
    template <typename T>
    static void accept_visitor(T* t, visitor& v) { v.visit(t); }

    static key_set_t s_keys;

private:
    //Derived-classes must be declared `VISITABLE'
    virtual void accept_(visitor& v );
    #define VISITABLE(KEY) \
        std::string unique_key() const override \
            { return KEY; } \
        void accept_(visitor& v) override \
        { \
            visited_base::s_keys.insert(unique_key()); \
            accept_visitor(this, v); \
        } 
};

#endif //#ifndef VISITED_BASE_HPP
