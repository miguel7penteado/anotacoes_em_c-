#ifndef INCLUDED_DATA_
#define INCLUDED_DATA_

#include "../union/union.h"

class Data
{
    Union::Field d_field;
    Union d_union;

    public:
        Data(int value = 0);             // 1.cc
        Data(Data const &other);         // 2.cc
        Data(Data &&tmp);                // 3.cc

        Data(std::string const &text);   // 4.cc

        ~Data();

        Data &operator=(Data const &other);
        Data &operator=(Data &&tmp);

        void swap(Data &other);

        Union::Field field() const;
        std::string const &text() const;
        int value() const;
};

inline Union::Field Data::field() const
{
    return d_field;
}

inline std::string const &Data::text() const
{
    return d_union.text();
}

inline int Data::value() const
{
    return d_union.value();
}

#endif
