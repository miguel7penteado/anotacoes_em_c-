#include "union.ih"

void Union::destroy(Field type)
{
    (this->*s_destroy[type])();
}
