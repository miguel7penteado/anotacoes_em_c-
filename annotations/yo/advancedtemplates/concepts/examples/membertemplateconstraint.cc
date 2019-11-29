
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

    template <typename Type>
    struct Data
    {
        template <Constraint Member>
        void process(Member par);       // a member template is constrained

        template <typename Tp>          // also, now via a variable constr.
        void another(Tp   par) requires Constraint2<Tp>;
    };

    template <typename T1>
    template <Constraint T2>
    void Data<T1>::process(T2 par)
    {}

    template <typename T1>
    template <typename T2>
    void Data<T1>::another(T2 par) requires Constraint2<T2>
    {}

int main()
{
    Data<int>{}.process(Combi{});
}
