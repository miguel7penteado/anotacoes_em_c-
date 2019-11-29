#include "union.ih"

void Union::move(Field type, Union &&tmp, Field next)
{
    swap(type, tmp, next);
}
