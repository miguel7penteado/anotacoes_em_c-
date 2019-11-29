#include "data.ih"

Data &Data::operator=(Data const &other)
{
    Data tmp{ other };
    swap(tmp);
    return *this;
}
