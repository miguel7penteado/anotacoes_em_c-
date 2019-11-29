    template <typename Type = int, int N = 10>
    concept bool C3 = true;

    template <typename Type>
    concept bool ID()
    {
        return true;
    }

    template <typename Type>
    concept bool IncAndDec()
    {
        return
            requires(Type par)
            {
                ++par;          // `Type' variables/objects must
                --par;          // support pre- and postfix
                par++;          // increment and decrement
                par--;          // operators
            };
    }

    template <typename Type>
    concept bool ReturnTypes()
    {
        return
            requires(Type par)
            {
                { ++par } -> Type &;    // prefix inc. returns a Type &
                { par[0] } -> char;     // the index operator returns a char
            };
    }

    template <typename Type>
    concept bool MultiArgs()
    {
        return
            requires(Type lhs, Type rhs)
            {
                { lhs + rhs   } -> Type;
                { lhs += rhs  } -> Type &;
                { lhs.c_str() } -> char const *;
            };
    }

    template <typename Type>
    concept bool CombiOps()
    {
        return
            requires(Type lhs, Type rhs)
            {
                { lhs + rhs   } -> Type;
                { lhs += rhs  } -> Type &;
            }
            and
            requires(Type lhs)
            {
                { lhs.c_str() } -> char const *;
            };
    }

    template <typename Type>
    concept bool ValueType()
    {
        return
            requires()
            {
                typename Type::value_type;
            };
    }

    template <ValueType Type>
    class Data
    {
    };

    struct EnumStruct
    {
        enum value_type
        {
            VALUE
        };
    };

    template <typename Type>
    concept bool InputIterator()
    {
        return true;
    }

    template <typename Type>
    concept bool OutputIterator()
    {
        return true;
    }

    template <typename Type>
    concept bool ForwardIterator()
    {
        return
            requires
            {
                requires InputIterator<Type>();
                requires OutputIterator<Type>();
            };
    }

    template <typename Type>
    concept bool BidirectionalIterator()
    {
        return
            requires
            {
                requires ForwardIterator<Type>();
                requires IncAndDec<Type>();
            };
    }

    template <typename Type>
    concept bool RandomAccessIterator()
    {
        return
            requires
            {
                requires BidirectionalIterator<Type>();
            }
            and
            requires(Type lhs, Type rhs)
            {
                { lhs + rhs };
                { lhs - rhs };
            };
    }

    template <BidirectionalIterator Type>
    struct Iterator
    {
        void fun();
    };

    template <RandomAccessIterator RAI>
    void rSort(RAI begin, RAI end)
    {}

int main()
{
//    Data<EnumStruct> data;

    Iterator<int> iter;
    iter = iter;

    rSort(10, 20);

    iter.fun();
}
