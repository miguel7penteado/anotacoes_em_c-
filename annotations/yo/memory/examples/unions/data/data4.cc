#include "data.ih"

Data::Data(string const &txt)
:
    d_field(Union::TEXT),
    d_union(txt)
{}
