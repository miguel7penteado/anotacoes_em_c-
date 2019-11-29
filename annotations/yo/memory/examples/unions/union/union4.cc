#include "union.ih"

Union::Union(Union &&tmp, Field type)        // nothing is initialized by
{                                               // default
    swap(VALUE, tmp, type);
}
