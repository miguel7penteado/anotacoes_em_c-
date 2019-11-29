#include "union.ih"

void Union::copy(Field type, Union const &other, Field next)
{
    Union tmp{ other, next };    // create a temp. copy
    swap(type, tmp, next);      // swap the current and tmp

    tmp.destroy(next);          // destroy the tmp object
}
