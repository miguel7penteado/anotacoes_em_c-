#include <iostream>
#include <string>
#include <unordered_map>

    template <typename Type>
    concept bool Addable =
        requires(Type lh, Type rh)
        {
            lh + rh;
        };

    template <Addable Type>
    concept bool Addable2 =
        requires(Type lh, Type rh)
        {
            lh += rh;
        };


    template<Addable Type>
    Type add(Type const &x, Type const &y)
    {
        return x + y;
    }

    template<typename Type>
    Type add2(Type const &x, Type const &y)
    {
        return x + y;
    }

using namespace std;

int main()
{
//    add("one"s, "two"s);
//    add(unordered_map<int, int>{}, unordered_map<int, int>{});
}
