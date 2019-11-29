    template <typename Type>
    concept bool Comparable()                           // function concept
    {
        return
            requires(Type lhs, Type rhs)
            {
                operator<(lhs, rhs);
            };
    }

    template <typename Type>
    concept bool Comparable2  =                          // variable concept
        requires(Type lhs, Type rhs)
        {
            operator<(lhs, rhs);
        };


    template<Comparable Type>               // concept names can be function
    Type const &min(Type const &x, Type const &y)   // and variable concepts
    {
        return y < x ? y : x;
    }

    template<Comparable2 Type>
    Type const &min(Type const &x, Type const &y)
    {
        return y < x ? y : x;
    }

    template<typename Type> requires Comparable2<Type>   // cannot be fun. con.
    Type const &min2(Type const &x, Type const &y)
    {
        return y < x ? y : x;
    }
