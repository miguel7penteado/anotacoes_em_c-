
    template <typename Type>
    concept bool Constraint()                           // function concept
    {
        return
            requires(Type lhs, Type rhs)
            {
                { lhs < rhs } -> bool;                  // multiple
                lhs + rhs;                              // constraints
//                typename Type::value_type;
            };
    }

    template <typename Type>
    concept bool Constraint2  =                          // variable concept
        requires(Type lhs, Type rhs)
        {
//            { operator<(lhs, rhs) } -> bool;          // both OK
            { lhs < rhs } -> bool;

            lhs + rhs;
            typename Type::value_type;
        };


//    template <typename Type> concept bool Constraint = true ;

struct Combi
{
    typedef int value_type;
};

bool operator<(Combi const &lhs, Combi const &rhs);
Combi operator+(Combi const &lhs, Combi const &rhs);


template <Constraint Type>              // declares a multiply
requires Constraint2<Type> void fun();   // constrained function template

int main()
{
    fun<Combi>();
}
