#include "union.ih"

void Union::copyText(Union const &other)
{
    new(&u_text) string{ other.u_text };
}
