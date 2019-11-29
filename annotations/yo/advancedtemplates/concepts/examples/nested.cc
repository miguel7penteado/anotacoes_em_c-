#include <utility>
#include <string>

//comparable
template <typename Type>
concept bool Comparable =
    requires (Type lhs, Type rhs)
    {
        { lhs == rhs }  // bool is implied
        { lhs != rhs }
    };

template <typename Type>
concept bool Subtractable =
    requires (Type lhs, Type rhs)
    {
        { lhs - rhs } -> int;
    };
//=
//incrementable
template <typename Type>
concept bool Incrementable =
    requires (Type type)
    {
        ++type;
        type++;
    };
//=
//dereference
template <typename Type>
concept bool ConstDereferenceable =
    requires(Type type)
    {
        { *type } -> typename Type::value_type const &
    };

template <typename Type>
concept bool Dereferenceable =
    requires(Type type)
    {
        { *type } -> typename Type::value_type &
    };
//=

//initerator
template <Comparable Type>
concept bool InIterator =
    requires(Type type)
    {
        requires Subtractable<Type>;
        requires Incrementable<Type>;
        requires ConstDereferenceable<Type>;
    };
//=

//outiterator
template <Comparable Type>
concept bool OutIterator =
    requires(Type type)
    {
        requires Subtractable<Type>;
        requires Incrementable<Type>;
        requires Dereferenceable<Type>;
    };
//=

//fwditerator
template <InIterator Type>
concept bool FwdIterator =
    requires(Type type)
    {
        requires OutIterator<Type>;
    };
//=

//bidir
template <FwdIterator Type>
concept bool BiIterator =
    requires(Type type)
    {
        --type;
        type--;
    };

template <BiIterator Type>
concept bool RndIterator =
    requires(Type type)
    {
        type += 0;
        type -= 0;
        type + 0;
        type - 0;
    };
//=

using namespace std;

struct InIt
{
    typedef int value_type;

    InIt &operator++();
    InIt operator++(int);

    int const &operator*() const;
};

bool operator==(InIt const &lh, InIt const &rh);
bool operator!=(InIt const &lh, InIt const &rh);
int  operator-(InIt const &lh, InIt const &rh);


struct OutIt: public InIt
{
    int &operator*();
};

struct BiIt: public OutIt
{
    InIt &operator--();
    InIt operator--(int);
};

struct RndIt: public BiIt
{
    RndIt &operator+=(int);
    RndIt &operator-=(int);
};

RndIt &operator+(RndIt const &lh, int);
RndIt &operator-(RndIt const &lh, int);

template <InIterator Type>
void inFun(Type tp)
{}

template <OutIterator Type>
void outFun(Type tp)
{}

template <FwdIterator Type>
void fwdFun(Type tp)
{}

template <BiIterator Type>
void biFun(Type tp)
{}

template <RndIterator Type>
void rndFun(Type tp)
{}

int main()
{
    inFun(InIt{});
//    outFun(InIt{});
    outFun(OutIt{});

    fwdFun(OutIt{});

    biFun(BiIt{});
//    biFun(InIt{});
//    biFun(OutIt{});

    rndFun(RndIt{});
}



//template <BasicIterator Type>
//concept bool Decrementable =
//    requires (Type type)
//    {
//        --type;
//        type--;
//    }
//;
