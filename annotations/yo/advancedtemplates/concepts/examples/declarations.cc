    template <typename Type>
    concept bool Subtractable =
        requires(Type lh, Type rh)
        {
            lh - rh;
        };

//functions
    template <typename Type>    // advice: define concepts in
    concept bool Addable =      // separate headers.
        requires(Type lh, Type rh)
        {
            lh + rh;
        };

    template <typename Type>    // declares an unconstrained
    void fun();                 // function template

    template <Addable Type>  // declares a constrained overloaded
    void fun();                 // function template

    template <typename Type>    // same, requirement follows fun
    void fun() requires Addable<Type>;

    template <typename Type>    // same, requirement precedes fun
    requires Addable<Type> void fun();
//=


//classes
    template <typename Type>    // unconstrained
    struct Data;                // declaration

    template <Addable Type>     // constrained declaration
    struct Data<Type>;          // (i.e., a specialization)

//  template <typename Type>    // same specialization
//  requires Addable<Type> struct Data<Type>;
//=

//multi
    template <typename Type>        // used concepts
    concept bool C1 = true;
    template <typename Type>
    concept bool C2 = true;

    template <C1 Type>              // multiply constrained
    requires C2<Type> void fun();   //    function template

    template <typename Type>        // same, using 'and'
    requires C1<Type> and C2<Type> void fun();

    template <typename Type>        // same, trailing 'requires'
    void fun() requires C1<Type> and C2<Type>;

    template <typename Type>
    struct Multi;

    template <C1 Type>              // multiply constrained
    requires C2<Type> struct Multi<Type>; // class template
//=
