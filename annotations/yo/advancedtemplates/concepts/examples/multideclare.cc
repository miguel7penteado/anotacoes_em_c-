#include <vector>
#include <string>
#include <iostream>

using namespace std;

template <typename Type>
concept bool Subtractable =
    requires(Type lh, Type rh)
    {
        lh - rh;
    };

template <typename Type>
concept bool Addable =
    requires(Type lh, Type rh)
    {
        lh + rh;
    };

//two
template <typename t1, typename t2>
requires Addable<t1> struct Data
{};

template <Subtractable Type>
struct Data<Type, int>
{};
//=

void fun()
{
    Data<vector<int>, int>{};
}
