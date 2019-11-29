#include <iostream>
#include <vector>

template <typename Type>
concept bool Addable =
    requires(Type lh, Type rh)
    {
        lh + rh;
    };

//generic
template <typename Tp>
struct Handler
{
    Handler()
    {
        std::cout << "Generic Handler\n";
    }
};
//=

//addable
template <Addable Tp>       // constrain Tp to addable types
struct Handler<Tp>
{
    Handler()
    {
        std::cout << "Handler for types supporting operator+\n";
    }
};
//=

//use
int main()
{
    Handler<std::vector<int>>{};    // generic
    Handler<int>{};                 // specialized
}
//=
