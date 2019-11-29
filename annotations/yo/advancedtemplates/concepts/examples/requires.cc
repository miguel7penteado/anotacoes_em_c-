#include <iostream>
#include <string>
#include <map>

template <typename Type>
concept bool Addable =
    requires(Type lh, Type rh)
    {
        lh + rh;
    };

//extra
template <Addable Type>
concept bool Extra =
    requires(Type lh, Type rh)
    {
        lh + rh;
    };

template <typename Type> requires Addable<Type>
concept bool Extra2 =
    requires(Type lh, Type rh)
    {
        lh + rh;
    };

    // not with concept variable definitions:
template <typename Type>
concept bool Extra3() requires Addable<Type>
{
    return
    requires(Type lh, Type rh)
    {
        lh + rh;
    };
}
//=

//requires
template<typename Type> requires Addable<Type>
Type add(Type const &x, Type const &y)
{
    return x + y;
}

// as declaration:
template<typename Type> requires Addable<Type>
Type add(Type const &x, Type const &y);

template<typename Type>
Type add2(Type const &x, Type const &y) requires Addable<Type>
{
    return x + y;
}

// as declaration:
template<typename Type>
Type add2(Type const &x, Type const &y) requires Addable<Type>;
//=

using namespace std;

int main()
{
    add("one"s, "two"s);
    add2("one"s, "two"s);
//    add(map<int, int>{}, map<int, int>{});
}
