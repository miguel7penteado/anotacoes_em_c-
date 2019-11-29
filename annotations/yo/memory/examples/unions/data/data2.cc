#include "data.ih"

Data::Data(Data const &other)
:
    d_field(other.d_field),
    d_union(other.d_union, d_field)
{}
