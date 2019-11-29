#include "data.ih"

Data::~Data()
{
    d_union.destroy(d_field);
}
