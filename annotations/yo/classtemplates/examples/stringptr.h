#ifndef INCLUDED_STRINGPTR_H_
#define INCLUDED_STRINGPTR_H_

#include <string>
#include <vector>
#include <iterator>

//STRINGPTR
class StringPtr: public std::vector<std::string *>
{
    public:
        class iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;

    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
};

class StringPtr::iterator: public
        std::iterator<std::random_access_iterator_tag, std::string>
{
    friend class StringPtr;

    friend bool operator==(iterator const &lhs, iterator const &rhs);
    friend int operator-(iterator const &lhs, iterator const &rhs);
    friend bool operator<(iterator const &lhs, iterator const &rhs);
    friend iterator operator+(iterator const &lhs, int step);
    friend iterator operator-(iterator const &lhs, int step);

    std::vector<std::string *>::iterator d_current;

    iterator(std::vector<std::string *>::iterator const &current);

    public:
        iterator &operator--();
        iterator operator--(int);
        iterator &operator++();
        iterator operator++(int);

        iterator &operator+=(int step); // increment over `n' steps
        iterator &operator-=(int step); // decrement over `n' steps

        std::string &operator*() const;
        std::string *operator->() const;// access the fields of the
                                        // struct an iterator points
                                        // to. E.g., it->length()
};
//=

//PRIVATEIMP
inline StringPtr::iterator::iterator(
    std::vector<std::string *>::iterator const &current)
:
    d_current(current)
{}
//=

//PREDEC
inline StringPtr::iterator &StringPtr::iterator::operator--()
{
    --d_current;
    return *this;
}
//=
//POSTDEC
inline StringPtr::iterator StringPtr::iterator::operator--(int)
{
    return iterator(d_current--);
}
//=
//PREINC
inline StringPtr::iterator &StringPtr::iterator::operator++()
{
    ++d_current;
    return *this;
}
//=
//POSTINC
inline StringPtr::iterator StringPtr::iterator::operator++(int)
{
    return iterator(d_current++);
}
//=
//OPEQ
inline bool operator==(StringPtr::iterator const &lhs,
                       StringPtr::iterator const &rhs)
{
    return lhs.d_current == rhs.d_current;
}
//=
//OPNEQ
inline bool operator!=(StringPtr::iterator const &lhs,
                       StringPtr::iterator const &rhs)
{
    return not (lhs == rhs);
}
//=
//OPSUB
inline int operator-(StringPtr::iterator const &lhs,
                     StringPtr::iterator const &rhs)
{
    return lhs.d_current - rhs.d_current;
}
//=
//OP*
inline std::string &StringPtr::iterator::operator*() const
{
    return **d_current;
}
//=
//CMP
inline bool operator<(StringPtr::iterator const &lhs,
                      StringPtr::iterator const &rhs)
{
    return lhs.d_current < rhs.d_current;
}
//=
//OPADD
inline StringPtr::iterator operator+(StringPtr::iterator const &lhs,
                                                                int step)
{
    StringPtr::iterator ret{ lhs };
    ret.d_current += step;          // avoids ambiguity
    return ret;
}
//=
//OP-
inline StringPtr::iterator operator-(StringPtr::iterator const &lhs,
                                                                int step)
{
    StringPtr::iterator ret{ lhs };
    ret.d_current -= step;          // avoids ambiguity
    return ret;
}
//=
//OPARITH
inline StringPtr::iterator &StringPtr::iterator::operator+=(int step)
{
    d_current += step;
    return *this;
}
inline StringPtr::iterator &StringPtr::iterator::operator-=(int step)
{
    d_current -= step;
    return *this;
}
//=
//OPARROW
inline std::string *StringPtr::iterator::operator->() const
{
    return *d_current;
}
//=
//BEGEND
inline StringPtr::iterator StringPtr::begin()
{
    return iterator(this->std::vector<std::string *>::begin());
}
inline StringPtr::iterator StringPtr::end()
{
    return iterator(this->std::vector<std::string *>::end());
}
//=
//RBEGEND
inline StringPtr::reverse_iterator StringPtr::rbegin()
{
    return reverse_iterator(end());
}
inline StringPtr::reverse_iterator StringPtr::rend()
{
    return reverse_iterator(begin());
}
//=

#endif
