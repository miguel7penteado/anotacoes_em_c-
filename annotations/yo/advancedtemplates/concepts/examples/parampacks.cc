#include <utility>
#include <string>
#include <vector>
#include <queue>

template <typename First>
int sum(First const &first)
{
    return first.size();
}

template <typename First, typename  ...Types>
int sum(First const &first, Types const &...types)
{
    return first.size() + sum(types...);
}

//-------------------------------------

//hassize
template <typename Types>
concept bool HasSize =
    requires (Types type)
    {
        { type.size() } -> size_t;
    };
//=

//sumfun
template <HasSize ...Types>
void fun(Types const &...obj)
{
    sum(std::forward<Types const &>(obj)...);
}
//=

//sizetypes
template <HasSize ...Types>
class SizeTypes
{
    // ...
};
//=

using namespace std;

int main()
{
    fun(queue<int>{}, vector<int>{}, string{});

//use
    SizeTypes<> mt1;
    SizeTypes<queue<int>, vector<int>> mt2;
    // SizeTypes<string[]> mt3;             won't compile
//=
}

// Jan 2019: defining concepts using parameter packs is OK,
//           but specifying requirements for each of the implied types
//           apparently is not possible.

//-------------------------------------

//    fun2(queue<int>{}, vector<int>{});
//    fun3(queue<int>{}, vector<int>{});

//template <typename ...Types>
//concept bool Pack2 =
//    requires (Types ...types)
//    {
//        typename decltype(types)::value_type;
//
//        //true;
//    };

// template <typename ...Types>
// concept bool Pack2()
// { return
//     true;
// //    requires (Types type)
// //    {
// //        type.size();
// //    };
// }

//template <typename ...Types>
//concept bool Pack2()
//{
//    return
//    requires (Types type)
//    {
//        type.size();
//    };
//}

//template <typename ...Types>
//requires Pack2<Types ...>
//    void fun2(Types ...obj)
////requires Pack2<Types ...>
//{
////    sum(std::forward<Types>(obj)...);
//}
//
//template <Pack ...Types>
//void fun3(Types ...obj)
//{
////    sum(std::forward<Types>(obj)...);
//}
