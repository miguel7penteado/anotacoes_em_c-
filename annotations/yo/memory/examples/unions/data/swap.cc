#include "data.ih"

void Data::swap(Data &other)
{
    d_union.swap(d_field, other.d_union, other.d_field);

    Union::Field field = d_field;           // swap the fields
    d_field = other.d_field;
    other.d_field = field;
}
