#include <string>
#include <iostream>
#include <type_traits>

template <typename Type, typename Ret>
concept bool ReturnTypes =
    requires(Type par)
    {
        { par[0] } -> Ret;     // par[..] returns a Ret
    };

struct XX
{
    char operator[](int idx) const
    {
        return 'a';
    }
};

template <typename Type, typename Ret> requires ReturnTypes<Type, Ret>
Ret ret(Type tp)
{
    return tp[0];
}

using namespace std;

int main()
{
    ret<XX, string>(XX{});
}
