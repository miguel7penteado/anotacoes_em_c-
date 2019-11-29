
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

    template <Constraint X>     // Constraint must be specified,
    void Data<X>::process()     // but the formal type name
    {                           // doesn't have to be Type
        int x = 0;
        int y = x;
        x = y << 1;
    }

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

    template <typename  Type> requires Constraint2<Type>
    struct Data3
    {
        void process();
        void another();
    };

    template <Constraint2 X>     // Constraint must be specified,
    void Data3<X>::process()     // but the formal type name
    {}                          // doesn't have to be Type


    template <typename X>       // Still constraint, due to Data3's
    void Data3<X>::another()    // constraints
    {}


//                              Not OK: must be variable concept:
//
//    template <typename  Type> requires Constraint<Type>
//    struct Data4
//    {
//        void process();
//    };
//
//    template <Constraint2 X>     // Constraint must be specified,
//    void Data4<X>::process()     // but the formal type name
//    {                           // doesn't have to be Type
//        int x = 0;
//        int y = x;
//        x = y << 1;
//    }


int main()
{
    Data<Combi>{}.process();
    Data2<Combi>{}.process();
}
