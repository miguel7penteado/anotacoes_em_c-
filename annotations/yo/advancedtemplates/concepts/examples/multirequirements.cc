    template <typename Type>
    concept bool Comparable()                           // function concept
    {
        return
            requires(Type lhs, Type rhs)
            {
                { operator<(lhs, rhs) } -> bool;        // multiple
                lhs + rhs;                              // constraints
                typename Type::value_type;
            };
    }

    template <typename Type>
    concept bool Comparable2  =                          // variable concept
        requires(Type lhs, Type rhs)
        {
            { operator<(lhs, rhs) } -> bool;
            lhs + rhs;
            typename Type::value_type;
        };


    template<Comparable Type>               // concept names can be function
    Type const &min1(Type const &x, Type const &y)   // and variable concepts
    {
        return y < x ? y : x;
    }

    template<Comparable2 Type>
    Type const &min2(Type const &x, Type const &y)
    {
        return y < x ? y : x;
    }

    template<typename Type> requires Comparable2<Type>   // cannot be fun. con.
    Type const &min3(Type const &x, Type const &y)
    {
        return y < x ? y : x;
    }

struct Combi
{
    typedef int value_type;
};

bool operator<(Combi const &lhs, Combi const &rhs);
Combi operator+(Combi const &lhs, Combi const &rhs);

int main()
{
    min1(Combi{}, Combi());
    min2(Combi{}, Combi());
    min3(Combi{}, Combi());
}
