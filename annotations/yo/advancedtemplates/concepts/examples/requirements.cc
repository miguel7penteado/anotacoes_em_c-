#include <map>

template <typename Type>
concept bool Addable =
    requires(Type lh, Type rh)
    {
        lh + rh;
    };

template <typename Type>
concept bool Incrementable =
    requires(Type tp)
    {
        ++tp;
    };


//and
template <typename Type>
concept bool And =
    requires(Type lh, Type rh)
    {
        lh + rh;
    }
    and requires(Type tp)
    {
        ++tp;
    };

template <And Type>
Type add(Type const &lh, Type const &rh)
{
    return lh + rh;
}
//=

using namespace std;

int main()
{
    add(0, 0);
//    add(map<int,int>{}, map<int,int>{});
}
