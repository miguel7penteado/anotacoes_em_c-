#include <iostream>
#include <vector>

    template <typename Type>    // make constraints available
    concept bool C1 = true;
    template <typename Type>
    concept bool C2 = true;


template <typename Type>
concept bool Addition =
    requires(Type lhs, Type rhs)
    {
        lhs + rhs;
    };

template <typename Type>
concept bool Subtraction =
    requires(Type lhs, Type rhs)
    {
        lhs - rhs;
    };

//template <Addition Type>                // first form: Type defined as
//Type adder(Type lhs, Type rhs)          // concept-constrained type
//{
//    return lhs + rhs;
//}


//template <typename Type>                // second form: typename Type
//    requires Addition<Type>             // explicitly requiring the concept
//Type adder(Type lhs, Type rhs)
//{
//    return lhs + rhs;
//}

template <typename Type>                // 3rd form: 1st requires introduces
    requires requires(Type lhs, Type rhs)   // the requires-clause, followed
             {                              // by the requires expression
                lhs + rhs;                  // (which may consist of and/or
            }                               // concatenated
Type adder(Type lhs, Type rhs)              // requires-expressions)
{
    return lhs + rhs;
}

void fun(int arg) requires requires(int x) { false; };

template <typename ...Types> concept bool Pack = true;

template <Pack ...Types>      // multiple
void fun2();

template <typename Type> concept bool Constraint = true;

template <Constraint Type>
class Data
{
    void process();
};

template <typename Type>
requires Constraint<Type> class Data;

template <Constraint Type>
class Data;

//    template <Constraint X>     // Constraint must be specified,
//    void Data<X>::process()        // but the formal type name
//    {                           // doesn't have to be Type
//    }

//    template <typename Type>    // generic template type parameter
//    class Data
//    {
//        void process() requires Constraint<Type>;
//    };
//
//    template <typename X>
//    void Data<X>::process() requires Constraint<X>
//    {};

template <typename Type> concept bool Concept = true;

//    template <Constraint Class>
//    class Data
//    {
//        template <Concept Member>
//        void process(Member par);
//    };
//
//    template <Constraint T1>
//    template <Concept T2>
//    void Data<T1>::process(T2 par)
//    {}


template <typename Tp>
struct Struct
{
    Struct()
    {
        std::cout << "Generic class template\n";
    }
    Struct(Struct const &other)
    {
        std::cout << "Generic class CC\n";
    }

    Struct &operator=(Struct const &other)
    {
        std::cout << "Generic operator=\n";
        return *this;
    }

    Struct &operator+=(Struct const &other)
    {
        std::cout << "Generic operator+=\n";
        return *this;
    }
};

template <Subtraction Tp>
struct S2: public Struct<Tp>
{
};

template <Addition Tp>
struct Struct<Tp>;

template <Subtraction Tp>
struct S2;


//template <Addition Tp>
//struct Struct<Tp>
//{
//    Struct()
//    {
//        std::cout << "Addition only class template\n";
//    }
//};

//template <typename Tp>      // declaration
//requires Addition<Tp> struct Struct<Tp>
//;
//
//template <Addition Tp>      // declaration
//struct Struct<Tp>
//;
//
//
//template <typename Tp>      // declaration
//requires Addition<Tp> struct Struct<Tp>;

//template <typename Tp>      // declaration
//requires C1<Tp> struct Struct<Tp>;

template <Addition Type>
void fun();

template <typename Type>
void fun() requires Addition<Type>;

template <typename Type>
requires Addition<Type> void fun();

    template <C1 Type>              // declares a multiply
    requires C2<Type> void fun();   // constrained function template

    template <typename Type>        // same, using 'and'
    requires C1<Type> and C2<Type> void fun();

    template <typename Type>        // same
    void fun() requires C1<Type> and C2<Type>;

int main()
{
//    fun(4);
//    adder(4, 6);
////    std::vector<int> vi;
////    adder(vi, vi);
//
//    fun2<int>();
//    fun2<int, double>();

//    Struct<int>{};
//    Struct<std::vector<int>>{};

    S2<int> s1{};
    S2<int> s2{s1};

    s1 = s2;
    s1 += s2;
}
