#include <string>
#include <iostream>
#include <queue>

//type
template <typename Type>
concept bool Iteratable =
    requires(Type tp)
    {
        typename Type::iterator;
        tp.begin();
    };

template <Iteratable Type>
auto iter(Type const &obj)
{
    return obj.begin();
}
//==

using namespace std;

int main()
{
    string str;
    cout << *iter(str);

    iter(queue<int>{});
}
