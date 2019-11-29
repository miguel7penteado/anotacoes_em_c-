#include "data.ih"

Data &Data::operator=(Data &&tmp)
{
    swap(tmp);
    return *this;
}
