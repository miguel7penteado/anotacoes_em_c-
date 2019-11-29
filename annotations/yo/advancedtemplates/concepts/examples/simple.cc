#include <string>
#include <map>
#include <iostream>

//addable
template <typename Type>
concept bool Addable =
    requires(Type par)
    {
        ++par;          // `Type' variables must support
        par++;          // pre-/postfix increment
    }
    and requires(Type lhs, Type rhs)    // and also addition
    {
        lhs + rhs;
    };
//=

//index
template <typename Type>
concept bool HasIndex =
    requires(Type tp)
    {
        typename Type::value_type;
        tp[0];
    };

template <HasIndex Type>
auto idx(Type const &obj, size_t idx)
{
    return obj[idx];
}
//=

using namespace std;

int main()
{
//    idx(1, 2);
    string str;
    cout << idx(str, 1) << endl;
}
