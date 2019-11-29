#include "union.ih"

void Union::swap2Value(Union &other)
{
    int value = u_value;
    u_value = other.u_value;
    other.u_value = value;
}
