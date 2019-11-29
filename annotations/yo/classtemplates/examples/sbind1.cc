#include <iostream>
#include <tuple>

struct Cons1
{
    Cons1()
    {
        std::cout << "cons1\n";
    }

    Cons1(Cons1 const &other)
    {
        std::cout << "cons1 copycons\n";
    }

    void fun() const
    {
        std::cout << "cons1 fun\n";
    }
};


struct Cons2
{
    Cons2()
    {
        std::cout << "cons2\n";
    }

    Cons2(Cons2 const &other)
    {
        std::cout << "cons2 copycons\n";
    }

    void fun() const
    {
        std::cout << "cons2 fun\n";
    }
};

class Data
{
    Cons1 d_cons1;
    Cons2 d_cons2;

    public:
        Cons1 getCons() const
        {
            std::cout << "getCons():\n";
            return d_cons1;
        }
        Cons1 const &cons1() const
        {
            std::cout << "cons1():\n";
            return d_cons1;
        }
        Cons2 const &cons2() const
        {
            std::cout << "cons2():\n";
            return d_cons2;
        }

//    template <size_t Nr>
//    auto get() const
//    {
//        if constexpr (Nr == 0)
//            return getCons();
//
//        if constexpr (Nr == 1)
//            return cons1();
//
//        if constexpr (Nr == 2)
//            return cons2();
//
//        static_assert(Nr >= 0 and Nr < 3);
//    }
};

//instead of defining get as class member: it can also be defined
// outside of the class:
//
// template <size_t Nr>
// auto get(Data const &data)
// {
//     if constexpr (Nr == 0)
//         return data.getCons();
//
//     if constexpr (Nr == 1)
//         return data.cons1();
//
//     if constexpr (Nr == 2)
//         return data.cons2();
//
//     static_assert(Nr >= 0 and Nr < 3);
// }

// the return types can also be more precisely defined:
template <size_t Nr>
decltype(auto) get(Data const &data)
{
    if constexpr (Nr == 0)
        return data.getCons();

    if constexpr (Nr == 1)
//        return static_cast<Cons1 const &>(data.cons1());
        return data.cons1();

    if constexpr (Nr == 2)
//        return static_cast<Cons2 const &>(data.cons2());
        return data.cons2();

    static_assert(Nr >= 0 and Nr < 3);
}

    // in which case the tuple_element calls get(data):

template<size_t Nr>
struct std::tuple_element<Nr, Data>
{
    using type = decltype( get<Nr>( declval<Data>() ) );
};


    // same as below, explicitly inside namespace std:
template<>
struct std::tuple_size<Data>
{
    public:
    static size_t const value = 3;
};

namespace std
{

//template<>
//class tuple_size<Data>: public integral_constant<size_t, 3>
//{};
//
// Same:
//
//template<>
//struct tuple_size<Data>
//{
//    static size_t const value = 3;
//};


//template<size_t Nr>
//class tuple_element<Nr, Data>
//{
//    public:
//        using type = decltype(declval<Data>().get<Nr>());
//};


}

using namespace std;

int main()
{
    Data data;

    cout << "\n------\n\n";

        // copies data
//    auto [ a, b, c ] = data;        // here copy constructors are called,

        // uses data
    auto const &[ a, b, c ] = data;   // here copy constructors are called,
        // in all cases, a, b and c themselves are references.


    cout << "\n------\n\n";

    a.fun();

    cout << "\n------\n\n";

    b.fun();

    cout << "\n------\n\n";

    c.fun();
}
