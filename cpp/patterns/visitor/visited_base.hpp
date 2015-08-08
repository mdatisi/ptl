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
    typedef std::unordered_set<std::string> key_set_t;
    class visitor
    {
    public:
        typedef std::map<std::string, std::function<void(visited_base*)>> 
            key_map_t;

        visitor(const key_map_t& key_map );

        //Returns empty string if [TODO]
        std::string get_safe_key(visited_base* p) const;

        virtual void visit(visited_base* p);

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

#endif
