#include "data.ih"

Data::Data(Data &&tmp)
:
    d_field(Union::VALUE),
    d_union(0)
{
    swap(tmp);
}
