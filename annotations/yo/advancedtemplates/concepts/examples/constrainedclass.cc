
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

    template <Constraint Type>
    struct Data
    {
        void process();
    };

//  template <Constraint X>     // Constraint may or may not be specified
    template <typename  X>     // as the constraints are implied by Data
    void Data<X>::process()     // the formal typename may also be different
    {}

    template <Constraint2 Type>
    struct Data2
    {
        void process();
    };

    template <Constraint2 X>     // Constraint must be specified,
    void Data2<X>::process()     // but the formal type name
    {                           // doesn't have to be Type
        int x = 0;
        int y = x;
        x = y << 1;
    }

    template <Constraint2 Type>
    struct Data3
    {
        void process();
    };

    template <Constraint2 X>     // Constraint must be specified,
    void Data3<X>::process()     // but the formal type name
    {                           // doesn't have to be Type
        int x = 0;
        int y = x;
        x = y << 1;
    }


int main()
{
    Data<Combi>{}.process();
    Data2<Combi>{}.process();
}
