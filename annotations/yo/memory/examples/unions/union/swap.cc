#include "union.ih"

void Union::swap(Field here, Union &other, Field there)
{
    (this->*s_swap[here][there])(other);
}
