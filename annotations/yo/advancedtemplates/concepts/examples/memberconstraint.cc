    template <typename Type>
    concept bool Addable =
        requires(Type lh, Type rh)
        {
            lh + rh;
        };


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
    {                                   // constraint applies only to a member
        void process() requires Addable<Type>;

        template <Addable Tp>
        void add(Tp tp);
    };

    template <typename  Typ>            // formal type names may differ
    void Data<Typ>::process() requires Addable<Typ> // from the class.
    {}

    template <typename  Typ>            // formal type names may differ
    template <Addable Tp>
    void Data<Typ>::add(Tp tp)
    {}


int main()
{
    Data<Combi>{}.process();
}
