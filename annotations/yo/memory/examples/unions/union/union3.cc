#include "union.ih"

Union::Union(Union const &other, Field type) // nothing is initialized by
{                                        // default
    (this->*s_copy[type])(other);
}
